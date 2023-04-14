/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void save_quest(var_t *var, FILE *file)
{
    size_t n = 0;
    char *str = NULL;

    fwrite("quest_progress: ", sizeof(char), 16, file);
    fwrite(int_to_str(var->quest_progress, NULL), sizeof(char), 1, file);
    fwrite("\n", sizeof(char), 1, file);
    fwrite("skeleton_life: ", sizeof(char), 15, file);
    str = int_to_str(var->skeleton->life, &n);
    fwrite(str, sizeof(char), n, file);
    fwrite("\n", sizeof(char), 1, file);
    fwrite("orc_life: ", sizeof(char), 10, file);
    str = int_to_str(var->orc->life, &n);
    fwrite(str, sizeof(char), n, file);
    fwrite("\n", sizeof(char), 1, file);
    free(str);
}
