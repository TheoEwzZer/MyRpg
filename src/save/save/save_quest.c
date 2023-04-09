/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void save_quest(var_t *var, FILE *file)
{
    fwrite("quest_progress: ", sizeof(char), 16, file);
    fwrite(int_to_str(var->quest_progress, NULL), sizeof(char), 1, file);
    fwrite("\n", sizeof(char), 1, file);
}
