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
#include <string.h>
#include <time.h>
#include <unistd.h>

#ifndef MY_RPG_H_

    #define MY_RPG_H_

    #define SKELETON var->skeleton
    #define BLACKSMITH var->blacksmith

    #define PI 3.141592741f

    #define MAX_LEAVES 25
    #define MAX_PARTICLES_LEAVES 50

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

    #define BLACKSMITH_DIALOG1 \
    "Take this armor !"

    #define BLACKSMITH_DIALOG2 \
    "Attack enemies who\nare higher up !"

    #define PRISCILLA_DIALOG1 \
    "Our village need you !\nTalk to the blacksmith !"

    #define PRISCILLA_DIALOG2 \
    "Attack enemies who\nare higher up !"

    #define BOB_DIALOG1 \
    "Talk to me later !"

    #define BOB_DIALOG2 \
    "Now you need to defeat the boss\nGo at the bottom of the map !"

typedef enum quest_e {
    PRISCILLA,
    ARMOR,
    ENEMIES,
    BOB,
    BOSS
} quest_t;

typedef struct character {
    bool attack;
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
    float direction_x;
    float oscillation;
    float rotation;
    float size;
    float speed;
    sfRectangleShape *shape;
    sfSprite *sprite;
    sfVector2f actual_pos;
    sfVector2f base_pos;
    sfVector2f direction;
} particle_t;

typedef struct dialog_s {
    sfFont *font;
    sfSprite *sprite;
    sfText *name;
    sfText *text;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f scale;
} dialog_t;

typedef struct var {
    bool has_talk_to_blacksmith;
    bool is_particle_active;
    bool is_talking_to_blacksmith;
    bool switch_side;
    char_t *blacksmith;
    char_t *girl;
    char_t *mc;
    char_t *orc;
    char_t *pnj;
    char_t *skeleton;
    dialog_t *dialog;
    particle_t particles_leaves[MAX_PARTICLES_LEAVES];
    particle_t particles_pnj[MAX_LEAVES];
    quest_t quest_progress;
    sfFloatRect *collider_bounds;
    sfRectangleShape **collider;
    sfRectangleShape *hitbox;
    sfRectangleShape *rect;
    sfRenderWindow *window;
    sfSprite **foreground;
    sfSprite *background_sprite;
    sfTexture *armor;
    sfVector2f orc_position;
    sfVector2f skeleton_position;
    sfView *view;
    size_t frame_count;
    sound_t *sound;
    unsigned int direction;
} var_t;

bool check_intersects(sfFloatRect p_bounds, var_t *var);
bool load_position_map(var_t *var, char *line);
bool load_position_player(var_t *var, char *line);
bool load_quest(var_t *var, char *line);
char *int_to_str(int nb, size_t *n);
int get_digits(int nb);
sfRenderWindow *create_window(void);
void attack_back(var_t *var);
void attack_front(var_t *var);
void attack_left(var_t *var);
void attack_move(var_t *var);
void attack_right(var_t *var);
void back_move(var_t *var);
void blacksmith_dialog(var_t *var);
void blacksmith_move(var_t *var);
void bob_dialog(var_t *var);
void check_enemies(var_t *var);
void check_event(var_t *var, sfEvent event);
void check_move(var_t *var, sfEvent event);
void check_move1(var_t *var, sfEvent event, sfFloatRect p_bounds);
void check_move2(var_t *var, sfEvent event, sfFloatRect p_bounds);
void create_barrier_collider(var_t *var);
void create_collider(var_t *var);
void create_dialog_box(var_t *var);
void create_foreground(var_t *var);
void create_house_collider(var_t *var);
void create_north_west_position(var_t *var);
void create_north_west_size(var_t *var);
void create_png_collider(var_t *var);
void create_sud_collider(var_t *var);
void create_tree_collider(var_t *var);
void create_water_collider(var_t *var);
void create_west_collider(var_t *var);
void display_orc(var_t *var);
void display_orc2(var_t *var);
void display_skeleton(var_t *var);
void display_skeleton2(var_t *var);
void front_move(var_t *var);
void game_engine(var_t *var);
void generate_leaves(var_t *var, sfTexture *leaf_texture);
void generate_particle_pnj(var_t *var, sfVector2f position);
void girl_move(var_t *var);
void init_char(var_t *var);
void init_enemies(var_t *var);
void init_game(var_t *var);
void init_player(var_t *var);
void init_rpg(var_t *var);
void init_struct(var_t *var);
void left_move(var_t *var);
void load_game(const char *file_name, var_t *var);
void move_leaves(var_t *var);
void move_particle_pnj(var_t *var);
void move_particle_position_pnj(var_t *var, sfVector2f position);
void pnj_move(var_t *var);
void priscilla_dialog(var_t *var);
void right_move(var_t *var);
void save_game(const char *file_name, var_t *var);
void save_position_map(var_t *var, FILE *file);
void save_position_player(var_t *var, FILE *file);
void save_quest(var_t *var, FILE *file);
void set_foreground_position(var_t *var);
void show_blacksmith_dialog(var_t *var);
void show_bob_dialog(var_t *var);
void show_priscilla_dialog(var_t *var);
void zoom_in(var_t *var, bool *has_zoom);
void zoom_out(var_t *var, bool *has_zoom);

#endif /* MY_RPG_H_ */
