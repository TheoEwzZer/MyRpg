/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void save_game(const char *file_name, var_t *var)
{
    FILE *file = fopen(file_name, "wb");

    if (!file)
        return;
    save_position_player(var, file);
    save_position_map(var, file);
    save_quest(var, file);
    save_position_skeleton(var, file);
    save_position_orc(var, file);
    save_player_life(var, file);
    save_boss(var, file);
    save_tutorial(var, file);
    fclose(file);
}

int get_digits(int nb)
{
    int digits = 0;

    if (nb == 0)
        return 1;
    if (nb < 0) {
        nb = -nb;
        digits++;
    }
    while (nb > 0) {
        nb /= 10;
        digits++;
    }
    return digits;
}

char *int_to_str(int nb, size_t *n)
{
    int digits = get_digits(nb);
    char *str = malloc(sizeof(char) * (size_t)(digits + 1));
    int i = 0, digit = 0;
    if (!str)
        return NULL;
    if (n)
        *n = (size_t)digits;
    memset(str, 0, (size_t)(digits + 1));
    if (nb < 0) {
        str[i] = '-';
        i++;
        nb = -nb;
    }
    while (digits > i) {
        digit = nb % 10;
        str[digits - 1] = (char)('0' + digit);
        nb /= 10;
        digits--;
    }
    return str;
}
