/*
** EPITECH PROJECT, 2023
** my_strcpy.c
** File description:
** Copies a string into another. The destination string will
** already have enough memory to copy the source string.
*/

#include <stdio.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    unsigned int len = my_strlen(src);

    for (unsigned int i = 0; i <= len; i++)
        dest[i] = src[i];
    return dest;
}
