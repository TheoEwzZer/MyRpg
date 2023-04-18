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
    #define BOSSV var->boss
    #define BOSSC var->boss->boss
    #define FIREBALL BOSSV->fireball

    #define INVENTORY var->inventory

    #define ENEMY_SPEED 0.03f

    #define PI 3.141592741f

    #define MAX_PARTICLES 10
    #define MAX_LEAVES 50
    #define MAX_FIREBALL 3

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

    #define RECT_CONTAINS(rectangle) \
    sfIntRect_contains(rectangle, event.mouseButton.x, event.mouseButton.y)

    #define INT_RECT(rect) \
    (int)rect.left, (int)rect.top, (int)rect.width, (int)rect.height

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
    direction_t direction;
    float fireball_second;
    float second;
    int exp;
    int life;
    sfBool attack;
    sfClock *fireball;
    sfClock *walk;
    sfIntRect rect;
    sfRectangleShape *hitbox;
    sfRectangleShape *spear;
    sfSprite *sprite;
    sfTexture *texture;
    sfTime fireball_t;
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
    sfMusic *music;
    sfSound *sound;
    sfSoundBuffer *buffer;
} sound_t;

typedef struct inventory_s {
    sfBool is_open;
    sfSprite *bar;
    sfSprite *lance;
    sfSprite *sprite;
    sfText *atk;
    sfTexture *exp0;
    sfTexture *exp1;
    sfTexture *exp2;
    sfTexture *exp3;
    sfTexture *exp4;
    sfTexture *exp5;
    sfTexture *exp6;
    sfTexture *exp7;
    sfTexture *spear;
    sfTexture *texture;
} inventory_t;

typedef struct menu_s {
    sfSprite *exit_sprite;
    sfSprite *main_menu_sprite;
    sfSprite *play_sprite;
    sfSprite *resume_sprite;
    sfSprite *setting_sprite;
} menu_t;

typedef struct settings_s {
    int gauge_m;
    int gauge_s;
    sfSprite *menu_sprite;
    sfSprite *gauge_m0;
    sfSprite *gauge_m1;
    sfSprite *gauge_m2;
    sfSprite *gauge_m3;
    sfSprite *gauge_m4;
    sfSprite *music_sprite;
    sfSprite *mute_music;
    sfSprite *mute_sound;
    sfSprite *res1;
    sfSprite *res2;
    sfSprite *resolution_sprite;
    sfSprite *size1;
    sfSprite *size2;
    sfSprite *size_sprite;
    sfSprite *gauge_s0;
    sfSprite *gauge_s1;
    sfSprite *gauge_s2;
    sfSprite *gauge_s3;
    sfSprite *gauge_s4;
    sfSprite *sound_sprite;
} settings_t;

typedef struct mouse_event_s {
    float scale_x;
    float scale_y;
    int x;
    int y;
} mouse_event_t;

typedef struct window_settings_s {
    int height;
    int style;
    int width;
    sfVector2u size;
} window_settings_t;

typedef struct fireball_s {
    sfBool is_active;
    sfRectangleShape *hitbox;
    sfSprite *sprite;
    sfVector2f direction;
} fireball_t;

typedef struct boss_s {
    char_t *boss;
    fireball_t **fireball;
    int boss_height;
    int boss_left;
    int boss_top;
    int boss_width;
    sfClock *clock;
    sfSprite *room;
    sfTexture *boss_room;
    sfTexture *fire;
    sfTexture *map;
    sfVector2f b_pos;
    sfVector2f p_pos;
} boss_t;

typedef struct var {
    boss_t *boss;
    char_t *blacksmith;
    char_t *girl;
    char_t *orc;
    char_t *player;
    char_t *pnj;
    char_t *skeleton;
    dialog_t *dialog;
    inventory_t *inventory;
    life_t *life;
    particle_t particles_leaves[MAX_LEAVES];
    particle_t particles_pnj[MAX_PARTICLES];
    quest_t quest_progress;
    quest_text_t *quest_text;
    sfBool has_talk_to_blacksmith;
    sfBool is_particle_active;
    sfBool is_talking_to_blacksmith;
    sfFloatRect *collider_bounds;
    sfRectangleShape **collider;
    sfRectangleShape *rect;
    sfRenderWindow *window;
    sfSprite **foreground;
    sfSprite *background_sprite;
    sfTexture *armor;
    sfView *default_view;
    sfView *view;
    size_t frame_count;
    sound_t *sound;
    window_settings_t *settings;
} var_t;

char *int_to_str(int nb, size_t *n);
int get_digits(int nb);
int main(void);
settings_t *init_settings(void);
sfBool check_intersects(sfFloatRect rect, var_t *var);
sfBool load_player_life(var_t *var, char *line);
sfBool load_position_map(var_t *var, char *line);
sfBool load_position_orc(var_t *var, char *line);
sfBool load_position_player(var_t *var, char *line);
sfBool load_position_player_x(var_t *var, char *line);
sfBool load_position_player_y(var_t *var, char *line);
sfBool load_position_skeleton(var_t *var, char *line);
sfBool load_quest(var_t *var, char *line);
sfFloatRect create_enemy_rect(sfVector2f direction, char_t *enemy);
sfRenderWindow *create_window(void);
sfVector2f get_fireball_direction(var_t *var);
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
void boss_fight(var_t *var);
void change_direction_orc(var_t *var, sfVector2f direction);
void change_direction_skeleton(var_t *var, sfVector2f direction);
void change_quest_text(var_t *var);
void change_quest_to_enemies(var_t *var);
void check_enemies(var_t *var);
void check_event(var_t *var, sfEvent event);
void check_fireball_collision(var_t *var);
void check_inventory(var_t *var, sfEvent event);
void check_life(var_t *var);
void check_move(var_t *var, sfEvent event);
void check_move1(var_t *var, sfEvent event, sfFloatRect p_bounds);
void check_move2(var_t *var, sfEvent event, sfFloatRect p_bounds);
void check_quest(var_t *var);
void choose_resolution(var_t *var, float scale_x, float scale_y, sfEvent event);
void create_barrier_collider(var_t *var);
void create_boss_room_collider(var_t *var);
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
void display_boss(var_t *var);
void display_life(var_t *var);
void display_menu(sfRenderWindow *window, menu_t *menu);
void display_menu_settings(sfRenderWindow *window, settings_t *menu);
void display_orc(var_t *var);
void display_skeleton(var_t *var);
void display_ui(var_t *var);
void down_move(var_t *var);
void draw_settings(settings_t *menu, sfRenderWindow *window);
void event_menu(var_t *var, sfEvent event, menu_t *menu);
void event_menu_settings(var_t *var, sfEvent event, settings_t *menu);
void fight_boss(var_t *var);
void fight_orc(var_t *var);
void fight_skeleton(var_t *var);
void game_engine(var_t *var, sfEvent event);
void game_engine2(var_t *var);
void generate_leaves(var_t *var, sfTexture *leaf_texture);
void generate_particle_pnj(var_t *var, sfVector2f position);
void girl_move(var_t *var);
void handle_music(var_t *var, settings_t *menu, mouse_event_t *mouse);
void handle_res(var_t *var, sfUint32 width, sfUint32 height, sfUint32 style);
void handle_sound(var_t *var, settings_t *menu, mouse_event_t *mouse);
void init_boss(var_t *var);
void init_char(var_t *var);
void init_fireball(var_t *var);
void init_game(var_t *var);
void init_life(var_t *var);
void init_menu(menu_t *menu);
void init_mute(settings_t *menu);
void init_orc(var_t *var);
void init_player(var_t *var);
void init_resolution(settings_t *menu);
void init_rpg(var_t *var);
void init_settings_three(settings_t *menu);
void init_settings_two(settings_t *menu);
void init_skeleton(var_t *var);
void init_sound(var_t *var);
void init_struct(var_t *var);
void init_ui(var_t *var);
void knockback(var_t *var, sfClock *clock, char_t *enemy);
void left_move(var_t *var);
void load_all(var_t *var, char *line);
void load_game(const char *file_name, var_t *var);
void load_game_and_engine(var_t *var, sfEvent event);
void load_inventory(var_t *var);
void main_menu(var_t *var);
void map(var_t *var);
void menu_settings(var_t *var);
void move_fireball(var_t *var, sfUint32 i);
void move_leaves(var_t *var);
void move_particle_pnj(var_t *var);
void move_particle_position_pnj(var_t *var, sfVector2f position);
void pnj_move(var_t *var);
void priscilla_dialog(var_t *var);
void right_move(var_t *var);
void save_game(const char *file_name, var_t *var);
void save_player_life(var_t *var, FILE *file);
void save_position_map(var_t *var, FILE *file);
void save_position_orc(var_t *var, FILE *file);
void save_position_player(var_t *var, FILE *file);
void save_position_skeleton(var_t *var, FILE *file);
void save_quest(var_t *var, FILE *file);
void set_fireball_position(var_t *var);
void set_foreground_position(var_t *var);
void show_blacksmith_dialog(var_t *var);
void show_bob_dialog(var_t *var);
void show_priscilla_dialog(var_t *var);
void up_move(var_t *var);
void zoom_in(var_t *var, sfBool *has_zoom);
void zoom_out(var_t *var, sfBool *has_zoom);
void get_exp(var_t *var);
void init_inventory(var_t *var);
void init_exp(var_t *var);
void display_inventory(var_t *var);
void stat_set_pos(var_t *var, float x, float y);
void check_exp(var_t *var);

#endif /* MY_RPG_H_ */
