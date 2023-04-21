/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

char *replace_backslash_n(char *line)
{
    char *new_line = malloc(sizeof(char) * (my_strlen(line) + 1));
    int j = 0;

    for (sfUint32 i = 0; line[i]; i++) {
        if (line[i] == '\\' && line[i + 1] == 'n') {
            new_line[j] = '\n';
            i++;
        } else {
            new_line[j] = line[i];
        }
        j++;
    }
    new_line[j] = '\0';
    return new_line;
}

sfBool load_dialog2(var_t *var, char *line)
{
    line = replace_backslash_n(line);
    if (!my_strncmp(line, "PRISCILLA_DIALOG2: ", 19)) {
        CONFIG->priscilla_dialog2 = my_strdup(line + 19);
        return sfTrue;
    }
    if (!my_strncmp(line, "BOB_DIALOG1: ", 13)) {
        CONFIG->bob_dialog = my_strdup(line + 13);
        return sfTrue;
    }
    if (!my_strncmp(line, "BOB_DIALOG2: ", 13)) {
        CONFIG->bob_dialog2 = my_strdup(line + 13);
        return sfTrue;
    }
    return sfFalse;
}

sfBool load_dialog(var_t *var, char *line)
{
    line = replace_backslash_n(line);
    if (!my_strncmp(line, "BLACKSMITH_DIALOG: ", 19)) {
        CONFIG->blacksmith_dialog = my_strdup(line + 19);
        return sfTrue;
    }
    if (!my_strncmp(line, "BLACKSMITH_DIALOG2: ", 20)) {
        CONFIG->blacksmith_dialog2 = my_strdup(line + 20);
        return sfTrue;
    }
    if (!my_strncmp(line, "TUTORIAL_BLACKSMITH: ", 21)) {
        CONFIG->tutorial_dialog = my_strdup(line + 21);
        return sfTrue;
    }
    if (!my_strncmp(line, "PRISCILLA_DIALOG: ", 18)) {
        CONFIG->priscilla_dialog = my_strdup(line + 18);
        return sfTrue;
    }
    return sfFalse;
}
