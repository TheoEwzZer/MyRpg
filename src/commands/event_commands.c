/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

int find_index(var_t *var, sfText **texts)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(var->window);
    sfVector2f mouse2 = {(float)mouse.x, (float)mouse.y};
    sfFloatRect rect;
    for (int i = 0; i < 6; i++){
        rect = sfText_getGlobalBounds(texts[i]);
        if (sfFloatRect_contains(&rect, mouse2.x, mouse2.y)){
            return i;
        }
    }
    return -1;
}

void assign_key(var_t *var, sfEvent event, int index)
{
    sfUint32 key = event.text.unicode - 97;
    if (key == 32) key = 57;
    if (index == 0)
        var->key_up = key;
    if (index == 1)
        var->key_down = key;
    if (index == 2)
        var->key_right = key;
    if (index == 3)
        var->key_left = key;
    if (index == 4)
        var->key_inv = key;
    if (index == 5)
        var->key_attack = key;
}

void commands_back(sfEvent event, var_t *var)
{
    sfVector2u size = sfRenderWindow_getSize(var->window);
    float scalex = (float)size.x / 1920;
    float scaley = (float)size.y / 1080;
    mouse_event_t *mouse = malloc(sizeof(mouse_event_t));

    mouse->x = event.mouseButton.x;
    mouse->y = event.mouseButton.y;
    mouse->scale_x = scalex;
    mouse->scale_y = scaley;
    if (event.mouseButton.x > 0 && event.mouseButton.x < 200 * scalex
    && event.mouseButton.y > 0 * scaley && event.mouseButton.y < 200 * scaley) {
        menu_settings(var, 1);
    }
}

void event_commands(var_t *var, sfEvent event, sfText **texts)
{
    static int index = -1; char *str = malloc(sizeof(char) * 6);
    if (event.type == sfEvtClosed ||
    (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyEscape)))
        sfRenderWindow_close(var->window);
    if (event.type == sfEvtMouseButtonReleased
    && event.mouseButton.button == sfMouseLeft){
        index = find_index(var, texts); commands_back(event, var);
    }
    if (event.type == sfEvtTextEntered && index != -1){
        assign_key(var, event, index);
        if (event.text.unicode == 32){
            str[0] = 'S'; str[1] = 'P'; str[2] = 'A'; str[3] = 'C';
            str[4] = 'E'; str[5] = '\0'; sfText_setString(texts[index], str);
            sfText_setCharacterSize(texts[index], 30);
            index = -1; return;
        }
        str[0] = (char)event.text.unicode; str[1] = '\0';
        sfText_setCharacterSize(texts[index], 50);
        sfText_setString(texts[index], str); index = -1;
    }
}
