/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 24};
    sfUint32 style = sfDefaultStyle;
    sfRenderWindow *window = sfRenderWindow_create(
        mode, "My Rpg", style, NULL
    );
    return window;
}

void check_event(var_t *var, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(var->window);
    if (event.type == sfEvtKeyPressed)
        check_move(var, event);
}

void init_player(var_t *var)
{
    var->mc->clothes = sfTexture_createFromFile("assets/player/mc.png", NULL);
    var->mc->sprite = sfSprite_create();
    sfSprite_setTexture(var->mc->sprite, var->mc->clothes, sfTrue);
    var->mc->walk = sfClock_create();
    var->mc->rect.top = 0;
    var->mc->rect.width = 77;
    var->mc->rect.height = 77;
    var->mc->rect.left = 0;
    sfSprite_setTextureRect(var->mc->sprite, var->mc->rect);
    sfSprite_setPosition(var->mc->sprite, (sfVector2f){1685, 1300});
    sfSprite_setScale(var->mc->sprite, (sfVector2f){0.75f, 0.75f});
    var->hitbox = sfRectangleShape_create();
    sfRectangleShape_setPosition(var->hitbox, (sfVector2f){1700, 1340});
}

void init_struct(var_t *var)
{
    sfImage *image = sfImage_createFromFile("assets/map/map.png");
    sfTexture *texture = sfTexture_createFromImage(image, NULL);
    var->mc = malloc(sizeof(char_t));
    init_player(var);
    var->background_sprite = sfSprite_create();
    sfSprite_setTexture(var->background_sprite, texture, sfTrue);
    var->window = create_window();
    var->view = sfView_createFromRect((sfFloatRect){0, 0, 640, 360});
    sfView_setCenter(var->view, (sfVector2f){1685, 1275});
    create_collider(var);
    sfView_zoom(var->view, 1.15f);
    var->frame_count = 0;
}

int main(void)
{
    var_t *var = malloc(sizeof(var_t));
    sfEvent event;
    sfTexture *leaf_texture = sfTexture_createFromFile("assets/leaf.png", NULL);
    sfSprite *particle_sprite = sfSprite_create();
    srand((unsigned)time(NULL));
    init_game(var);
    init_struct(var);
    sfMusic_setLoop(var->sound->theme, sfTrue);
    sfMusic_play(var->sound->theme);
    sfSprite_setTexture(particle_sprite, leaf_texture, sfTrue);
    sfSprite_setScale(particle_sprite, (sfVector2f){0.005f, 0.005f});
    generate_particle(var);
    game_engine(var, particle_sprite, event);
}
