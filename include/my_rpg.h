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

    #define GET_BOUNDS(rectangle) \
    sfRectangleShape_getGlobalBounds(rectangle)

    #define DRAW_RECTANGLE(rectangle) \
    sfRenderWindow_drawRectangleShape(var->window, rectangle, NULL)

    #define DRAW_SPRITE(sprite) \
    sfRenderWindow_drawSprite(var->window, sprite, NULL)

typedef struct character {
    sfSprite *sprite;
    sfTexture *clothes;
    sfIntRect rect;
    sfTime times;
    sfClock *walk;
    float second;
} char_t ;

typedef struct sound_s {
    sfMusic *theme;
} sound_t ;

typedef struct var {
    char_t *forge;
    char_t *girl;
    char_t *mc;
    char_t *pnj;
    sfFloatRect *collider_bounds;
    sfRectangleShape **collider;
    sfRectangleShape *hitbox;
    sfRectangleShape *rect;
    sfRenderWindow *window;
    sfSprite *background_sprite;
    sfView *view;
    sound_t *sound;
} var_t;

bool check_intersects(sfFloatRect p_bounds, var_t *var);
sfRenderWindow *create_window(void);
void back_move(var_t *var);
void check_event(var_t *var, sfEvent event);
void check_move(var_t *var, sfEvent event);
void check_move1(var_t *var, sfEvent event, sfFloatRect p_bounds);
void check_move2(var_t *var, sfEvent event, sfFloatRect p_bounds);
void create_barrer_collider(var_t *var);
void create_collider(var_t *var);
void create_house_collider(var_t *var);
void create_north_ouest_position(var_t *var);
void create_north_ouest_size(var_t *var);
void create_png_collider(var_t *var);
void create_sud_collider(var_t *var);
void create_tree_collider(var_t *var);
void create_water_collider(var_t *var);
void create_west_collider(var_t *var);
void forge_move(var_t *var);
void front_move(var_t *var);
void girl_move(var_t *var);
void init_char(var_t *var);
void init_game(var_t *var);
void init_player(var_t *var);
void init_struct(var_t *var);
void left_move(var_t *var);
void pnj_move(var_t *var);
void right_move(var_t *var);

#endif /* MY_RPG_H_ */
