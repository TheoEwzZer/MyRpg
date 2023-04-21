/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

sfBool load_value(var_t *var, char *line)
{
    if (!my_strncmp(line, "MAX_FIREBALL: ", 14)) {
        CONFIG->max_fireball = (sfUint32)my_getnbr(line + 14);
        return sfTrue;
    }
    if (!my_strncmp(line, "MAX_LEAVES: ", 12)) {
        CONFIG->max_leaves = (sfUint32)my_getnbr(line + 12);
        return sfTrue;
    }
    if (!my_strncmp(line, "MAX_PARTICLES: ", 15)) {
        CONFIG->max_particles = (sfUint32)my_getnbr(line + 15);
        return sfTrue;
    }
    return sfFalse;
}

void load_all_config(var_t *var, char *line)
{
    if (load_dialog(var, line))
        return;
    if (load_dialog2(var, line))
        return;
    if (load_value(var, line))
        return;
}

void load_config(const char *file_name, var_t *var)
{
    FILE *file = fopen(file_name, "rb");
    char *line = NULL;
    size_t len = 0;

    if (!file)
        return;
    CONFIG = malloc(sizeof(config_t));
    while (getline(&line, &len, file) != -1)
        load_all_config(var, line);
    fclose(file);
    if (line)
        free(line);
}
