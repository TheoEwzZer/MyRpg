/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void save_tutorial(var_t *var, FILE *file)
{
    char *str = NULL;
    sfVector2f position = sfText_getPosition(var->tutorial->text);
    size_t n = 0;

    fwrite("tutorial: ", sizeof(char), 10, file);
    fwrite(int_to_str(var->tutorial->is_active, NULL), sizeof(char), 1, file);
    fwrite("\n", sizeof(char), 1, file);
    fwrite("tutorial_position_x: ", sizeof(char), 21, file);
    str = int_to_str((int)position.x, &n);
    fwrite(str, sizeof(char), n, file);
    fwrite("\n", sizeof(char), 1, file);
    fwrite("tutorial_position_y: ", sizeof(char), 21, file);
    str = int_to_str((int)position.y, &n);
    fwrite(str, sizeof(char), n, file);
    fwrite("\n", sizeof(char), 1, file);
    free(str);
}
