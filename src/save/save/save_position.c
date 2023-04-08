/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void save_position_player(var_t *var, FILE *file)
{
    sfVector2f pos = sfSprite_getPosition(var->mc->sprite);
    size_t n = 0;
    char *str = NULL;

    fwrite("player_position_x: ", sizeof(char), 19, file);
    str = int_to_str((int)pos.x, &n);
    fwrite(str, sizeof(char), n, file);
    fwrite("\n", sizeof(char), 1, file);
    fwrite("player_position_y: ", sizeof(char), 19, file);
    str = int_to_str((int)pos.y, &n);
    fwrite(str, sizeof(char), n, file);
    fwrite("\n", sizeof(char), 1, file);
    free(str);
}

void save_position_map(var_t *var, FILE *file)
{
    sfVector2f map_pos = sfView_getCenter(var->view);
    size_t n = 0;
    char *str = NULL;

    fwrite("map_position_x: ", sizeof(char), 16, file);
    str = int_to_str((int)map_pos.x, &n);
    fwrite(str, sizeof(char), n, file);
    fwrite("\n", sizeof(char), 1, file);
    fwrite("map_position_y: ", sizeof(char), 16, file);
    str = int_to_str((int)map_pos.y, &n);
    fwrite(str, sizeof(char), n, file);
    fwrite("\n", sizeof(char), 1, file);
    free(str);
}
