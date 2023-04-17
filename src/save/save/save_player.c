/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void save_position_player(var_t *var, FILE *file)
{
    sfVector2f position = sfSprite_getPosition(PLAYER->sprite);
    size_t n = 0;
    char *str = NULL;

    fwrite("player_position_x: ", sizeof(char), 19, file);
    str = int_to_str((int)position.x, &n);
    fwrite(str, sizeof(char), n, file);
    fwrite("\n", sizeof(char), 1, file);
    fwrite("player_position_y: ", sizeof(char), 19, file);
    str = int_to_str((int)position.y, &n);
    fwrite(str, sizeof(char), n, file);
    fwrite("\n", sizeof(char), 1, file);
    free(str);
}

void save_player_life(var_t *var, FILE *file)
{
    size_t n = 0;
    char *str = NULL;

    fwrite("player_life: ", sizeof(char), 13, file);
    str = int_to_str(PLAYER->life, &n);
    fwrite(str, sizeof(char), n, file);
    fwrite("\n", sizeof(char), 1, file);
    free(str);
}
