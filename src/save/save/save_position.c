/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void save_position_map(var_t *var, FILE *file)
{
    sfVector2f map_position = sfView_getCenter(var->view);
    size_t n = 0;
    char *str = NULL;

    fwrite("map_position_x: ", sizeof(char), 16, file);
    str = int_to_str((int)map_position.x, &n);
    fwrite(str, sizeof(char), n, file);
    fwrite("\n", sizeof(char), 1, file);
    fwrite("map_position_y: ", sizeof(char), 16, file);
    str = int_to_str((int)map_position.y, &n);
    fwrite(str, sizeof(char), n, file);
    fwrite("\n", sizeof(char), 1, file);
    free(str);
}

void save_position_skeleton(var_t *var, FILE *file)
{
    sfVector2f position = sfSprite_getPosition(SKELETON->sprite);
    size_t n = 0;
    char *str = NULL;

    fwrite("skeleton_position_x: ", sizeof(char), 21, file);
    str = int_to_str((int)position.x, &n);
    fwrite(str, sizeof(char), n, file);
    fwrite("\n", sizeof(char), 1, file);
    fwrite("skeleton_position_y: ", sizeof(char), 21, file);
    str = int_to_str((int)position.y, &n);
    fwrite(str, sizeof(char), n, file);
    fwrite("\n", sizeof(char), 1, file);
    free(str);
}

void save_position_orc(var_t *var, FILE *file)
{
    sfVector2f position = sfSprite_getPosition(ORC->sprite);
    size_t n = 0;
    char *str = NULL;

    fwrite("orc_position_x: ", sizeof(char), 16, file);
    str = int_to_str((int)position.x, &n);
    fwrite(str, sizeof(char), n, file);
    fwrite("\n", sizeof(char), 1, file);
    fwrite("orc_position_y: ", sizeof(char), 16, file);
    str = int_to_str((int)position.y, &n);
    fwrite(str, sizeof(char), n, file);
    fwrite("\n", sizeof(char), 1, file);
    free(str);
}
