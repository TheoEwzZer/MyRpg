/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** my_rpg.h
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef MY_RPG_H_

    #define MY_RPG_H_

typedef struct var {
    sfRenderWindow *window;
} var_t;

sfRenderWindow *create_window(void);

#endif /* MY_RPG_H_ */
