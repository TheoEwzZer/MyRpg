/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void load_all(var_t *var, char *line)
{
    if (load_position_player(var, line))
        return;
    if (load_position_map(var, line))
        return;
    if (load_quest(var, line))
        return;
    if (load_position_skeleton(var, line))
        return;
    if (load_position_orc(var, line))
        return;
    if (load_player_life(var, line))
        return;
}

void load_game(const char *file_name, var_t *var)
{
    FILE *file = fopen(file_name, "rb");
    char *line = NULL;
    size_t len = 0;

    if (!file)
        return;
    while (getline(&line, &len, file) != -1)
        load_all(var, line);
    fclose(file);
    if (line)
        free(line);
}
