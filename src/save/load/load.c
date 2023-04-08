/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void load_game(const char *file_name, var_t *var)
{
    FILE *file = fopen(file_name, "rb");
    char *line = NULL;
    size_t len = 0;

    if (!file)
        return;
    while (getline(&line, &len, file) != -1) {
        if (load_position_player(var, line))
            continue;
        if (load_position_map(var, line))
            continue;
        if (load_quest(var, line))
            continue;
    }
    fclose(file);
    if (line)
        free(line);
}
