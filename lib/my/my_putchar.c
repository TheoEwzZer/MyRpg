/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** Print one caractere
*/
#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}
