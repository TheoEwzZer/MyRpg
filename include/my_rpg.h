/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** my_rpg.h
*/

#include "my.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <fcntl.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#ifndef MY_RPG_H_

    #define MY_RPG_H_

    #define PI 3.141592741f

    #define MAX_PARTICLES 10

    #define WIDTH 1920
    #define HEIGHT 1080

    #define GET_BOUNDS(rectangle) \
    sfRectangleShape_getGlobalBounds(rectangle)

    #define DRAW_RECTANGLE(rectangle) \
    sfRenderWindow_drawRectangleShape(var->window, rectangle, NULL)

    #define DRAW_SPRITE(sprite) \
    sfRenderWindow_drawSprite(var->window, sprite, NULL)

    #define CREATE_FROM_FILE(filename) \
    sfTexture_createFromFile(filename, NULL)

typedef struct character {
    float second;
    sfClock *walk;
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *clothes;
    sfTime times;
} char_t ;

typedef struct sound_s {
    sfMusic *theme;
} sound_t ;

typedef struct particle_s {
    float life;
    float oscillation;
    float rotation;
    float rotationSpeed;
    float size;
    float speed;
    float x;
    float y;
    sfVector2f direction;
} particle_t;

typedef struct var {
    bool has_armor;
    bool switch_side;
    char_t *forge;
    char_t *girl;
    char_t *mc;
    char_t *orc;
    char_t *pnj;
    char_t *skel;
    particle_t particles[MAX_PARTICLES];
    sfFloatRect *collider_bounds;
    sfRectangleShape **collider;
    sfRectangleShape *hitbox;
    sfRectangleShape *rect;
    sfRenderWindow *window;
    sfSprite **foreground;
    sfSprite *background_sprite;
    sfTexture *armor;
    sfVector2f orc_pos;
    sfVector2f skel_pos;
    sfView *view;
    size_t frame_count;
    sound_t *sound;
} var_t;

bool check_intersects(sfFloatRect p_bounds, var_t *var);
sfRenderWindow *create_window(void);
void back_move(var_t *var);
void check_ennemies(var_t *var);
void check_event(var_t *var, sfEvent event);
void check_move(var_t *var, sfEvent event);
void check_move1(var_t *var, sfEvent event, sfFloatRect p_bounds);
void check_move2(var_t *var, sfEvent event, sfFloatRect p_bounds);
void create_barrer_collider(var_t *var);
void create_collider(var_t *var);
void create_foreground(var_t *var);
void create_house_collider(var_t *var);
void create_north_ouest_position(var_t *var);
void create_north_ouest_size(var_t *var);
void create_png_collider(var_t *var);
void create_sud_collider(var_t *var);
void create_tree_collider(var_t *var);
void create_water_collider(var_t *var);
void create_west_collider(var_t *var);
void display_orc(var_t *var);
void display_orc2(var_t *var);
void display_skel(var_t *var);
void display_skel2(var_t *var);
void forge_move(var_t *var);
void front_move(var_t *var);
void game_engine(var_t *var, sfSprite *particle_sprite, sfEvent event);
void generate_particle(var_t *var);
void girl_move(var_t *var);
void init_char(var_t *var);
void init_ennemies(var_t *var);
void init_game(var_t *var);
void init_player(var_t *var);
void init_struct(var_t *var);
void left_move(var_t *var);
void move_particle(var_t *var, sfSprite *particle_sprite);
void pnj_move(var_t *var);
void right_move(var_t *var);
void set_foreground_position(var_t *var);

#endif /* MY_RPG_H_ */
