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

    #define COLLIDER var->collider

    #define BLACKSMITH var->blacksmith
    #define ORC var->orc
    #define SKELETON var->skeleton
    #define PLAYER var->player

    #define INVENTORY var->inventory

    #define ENEMY_SPEED 0.03f

    #define PI 3.141592741f

    #define MAX_PARTICLES 10
    #define MAX_LEAVES 50

    #define WIDTH 1920
    #define HEIGHT 1080

    #define SOUND var->sound

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

typedef struct dialog_s {
    sfFont *font;
    sfSprite *sprite;
    sfText *name;
    sfText *text;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f scale;
} dialog_t;

typedef enum direction_e {
    UP,
    DOWN,
    LEFT,
    RIGHT
} direction_t;

typedef struct character {
    bool attack;
    direction_t direction;
    float second;
    int life;
    sfClock *walk;
    sfIntRect rect;
    sfRectangleShape *hitbox;
    sfRectangleShape *spear;
    sfSprite *sprite;
    sfTexture *clothes;
    sfTime times;
} char_t ;

typedef struct life_s {
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *hp;
    sfVector2f pos;
} life_t ;

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

typedef struct quest_text_s {
    sfSprite *box;
    sfText *text;
    sfVector2f position;
    sfVector2f scale;
} quest_text_t;

typedef enum quest_e {
    PRISCILLA,
    ARMOR,
    ENEMIES,
    BOB,
    BOSS
} quest_t;

typedef struct sound_s {
    sfMusic *theme;
    sfSound *spear;
    sfSoundBuffer *spear_buf;
} sound_t;

typedef struct inventory_s {
    bool is_open;
    sfSprite *sprite;
    sfTexture *texture;
} inventory_t;

typedef struct var {
    bool has_talk_to_blacksmith;
    bool is_particle_active;
    bool is_talking_to_blacksmith;
    char_t *blacksmith;
    char_t *girl;
    char_t *orc;
    char_t *player;
    char_t *pnj;
    char_t *skeleton;
    dialog_t *dialog;
    life_t *life;
    particle_t particles_leaves[MAX_LEAVES];
    particle_t particles_pnj[MAX_PARTICLES];
    quest_t quest_progress;
    quest_text_t *quest_text;
    sfFloatRect *collider_bounds;
    sfRectangleShape **collider;
    sfRectangleShape *rect;
    sfRenderWindow *window;
    sfSprite **foreground;
    sfSprite *background_sprite;
    sfTexture *armor;
    sfView *view;
    size_t frame_count;
    sound_t *sound;
    inventory_t *inventory;
} var_t;

bool check_intersects(sfFloatRect p_bounds, var_t *var);
bool load_position_map(var_t *var, char *line);
bool load_position_orc(var_t *var, char *line);
bool load_position_player(var_t *var, char *line);
bool load_position_player_x(var_t *var, char *line);
bool load_position_player_y(var_t *var, char *line);
bool load_position_skeleton(var_t *var, char *line);
bool load_quest(var_t *var, char *line);
char *int_to_str(int nb, size_t *n);
int get_digits(int nb);
sfFloatRect create_enemy_rect(sfVector2f direction, char_t *enemy);
sfRenderWindow *create_window(void);
void animate_orc(var_t *var);
void animate_skeleton(var_t *var);
void attack_down(var_t *var);
void attack_left(var_t *var);
void attack_move(var_t *var);
void attack_right(var_t *var);
void attack_up(var_t *var);
void blacksmith_dialog(var_t *var);
void blacksmith_move(var_t *var);
void bob_dialog(var_t *var);
void change_direction_orc(var_t *var, sfVector2f direction);
void change_direction_skeleton(var_t *var, sfVector2f direction);
void change_quest_text(var_t *var);
void change_quest_to_enemies(var_t *var);
void check_enemies(var_t *var);
void check_event(var_t *var, sfEvent event);
void check_inventory(var_t *var, sfEvent event);
void check_life(var_t *var);
void check_move(var_t *var, sfEvent event);
void check_move1(var_t *var, sfEvent event, sfFloatRect p_bounds);
void check_move2(var_t *var, sfEvent event, sfFloatRect p_bounds);
void check_quest(var_t *var);
void create_barrier_collider(var_t *var);
void create_collider(var_t *var);
void create_collider2(var_t *var);
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
void dialog(var_t *var);
void display_life(var_t *var);
void display_orc(var_t *var);
void display_skeleton(var_t *var);
void display_ui(var_t *var);
void down_move(var_t *var);
void fight_orc(var_t *var);
void fight_skeleton(var_t *var);
void game_engine(var_t *var);
void generate_leaves(var_t *var, sfTexture *leaf_texture);
void generate_particle_pnj(var_t *var, sfVector2f position);
void girl_move(var_t *var);
void init_char(var_t *var);
void init_game(var_t *var);
void init_life(var_t *var);
void init_orc(var_t *var);
void init_player(var_t *var);
void init_rpg(var_t *var);
void init_skeleton(var_t *var);
void init_sound(var_t *var);
void init_struct(var_t *var);
void init_ui(var_t *var);
void knockback(var_t *var, sfClock *clock, char_t *enemy);
void left_move(var_t *var);
void load_all(var_t *var, char *line);
void load_game(const char *file_name, var_t *var);
void load_inventory(var_t *var);
void move_leaves(var_t *var);
void move_particle_pnj(var_t *var);
void move_particle_position_pnj(var_t *var, sfVector2f position);
void pnj_move(var_t *var);
void priscilla_dialog(var_t *var);
void right_move(var_t *var);
void save_game(const char *file_name, var_t *var);
void save_position_map(var_t *var, FILE *file);
void save_position_orc(var_t *var, FILE *file);
void save_position_player(var_t *var, FILE *file);
void save_position_skeleton(var_t *var, FILE *file);
void save_quest(var_t *var, FILE *file);
void set_foreground_position(var_t *var);
void show_blacksmith_dialog(var_t *var);
void show_bob_dialog(var_t *var);
void show_priscilla_dialog(var_t *var);
void up_move(var_t *var);
void zoom_in(var_t *var, bool *has_zoom);
void zoom_out(var_t *var, bool *has_zoom);

#endif /* MY_RPG_H_ */
