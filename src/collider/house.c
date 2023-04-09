/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void create_house_collider(var_t *var)
{
    sfRectangleShape_setPosition(COLLIDER[0], (sfVector2f){1656.0f, 1144.0f});
    sfRectangleShape_setPosition(COLLIDER[26], (sfVector2f){864.0f, 1000.0f});
    sfRectangleShape_setPosition(COLLIDER[27], (sfVector2f){HEIGHT, 1000.0f});
    sfRectangleShape_setPosition(COLLIDER[28], (sfVector2f){576.0f, 1324.0f});
    sfRectangleShape_setPosition(COLLIDER[29], (sfVector2f){252.0f, 1432.0f});
    sfRectangleShape_setPosition(COLLIDER[30], (sfVector2f){144.0f, 1144.0f});
    sfRectangleShape_setPosition(COLLIDER[31], (sfVector2f){288.0f, 784.0f});
    sfRectangleShape_setPosition(COLLIDER[32], (sfVector2f){468.0f, 784.0f});
    sfRectangleShape_setPosition(COLLIDER[34], (sfVector2f){864.0f, 604.0f});
    sfRectangleShape_setPosition(COLLIDER[35], (sfVector2f){900.0f, 718.0f});
    sfRectangleShape_setSize(COLLIDER[0], (sfVector2f){144.0f, 150.0f});
    sfRectangleShape_setSize(COLLIDER[26], (sfVector2f){216.0f, 186.0f});
    sfRectangleShape_setSize(COLLIDER[27], (sfVector2f){36.0f, 150.0f});
    sfRectangleShape_setSize(COLLIDER[28], (sfVector2f){144.0f, 150.0f});
    sfRectangleShape_setSize(COLLIDER[29], (sfVector2f){144.0f, 150.0f});
    sfRectangleShape_setSize(COLLIDER[30], (sfVector2f){180.0f, 150.0f});
    sfRectangleShape_setSize(COLLIDER[31], (sfVector2f){180.0f, 186.0f});
    sfRectangleShape_setSize(COLLIDER[32], (sfVector2f){72.0f, 150.0f});
    sfRectangleShape_setSize(COLLIDER[34], (sfVector2f){252.0f, 114.0f});
    sfRectangleShape_setSize(COLLIDER[35], (sfVector2f){180.0f, 36.0f});
}

void set_foreground_position(var_t *var)
{
    var->foreground = malloc(sizeof(sfSprite *) * 9);
    for (unsigned int i = 0; i < 9; i++)
        var->foreground[i] = sfSprite_create();
    sfSprite_setPosition(var->foreground[0], (sfVector2f){1656.0f, 1114.0f});
    sfSprite_setPosition(var->foreground[1], (sfVector2f){252.0f, 1402.0f});
    sfSprite_setPosition(var->foreground[2], (sfVector2f){576.0f, 1294.0f});
    sfSprite_setPosition(var->foreground[3], (sfVector2f){144.0f, 1114.0f});
    sfSprite_setPosition(var->foreground[4], (sfVector2f){288.0f, 754.0f});
    sfSprite_setPosition(var->foreground[5], (sfVector2f){864.0f, 574.0f});
    sfSprite_setPosition(var->foreground[6], (sfVector2f){864.0f, 970.0f});
    sfSprite_setPosition(var->foreground[7], (sfVector2f){1058.0f, 790.0f});
    sfSprite_setPosition(var->foreground[8], (sfVector2f){1440.0f, 718.0f});
}

void create_foreground(var_t *var)
{
    sfTexture *little_house = CREATE_FROM_FILE("assets/map/little_house.png");
    sfTexture *little_house2 = CREATE_FROM_FILE("assets/map/little_house2.png");
    sfTexture *medium_house = CREATE_FROM_FILE("assets/map/medium_house.png");
    sfTexture *big_house = CREATE_FROM_FILE("assets/map/big_house.png");
    sfTexture *big_house2 = CREATE_FROM_FILE("assets/map/big_house2.png");
    sfTexture *barrier = CREATE_FROM_FILE("assets/map/barrier.png");
    sfTexture *medium_house2 = CREATE_FROM_FILE("assets/map/medium_house2.png");

    set_foreground_position(var);
    sfSprite_setTexture(var->foreground[0], little_house, sfTrue);
    sfSprite_setTexture(var->foreground[1], little_house, sfTrue);
    sfSprite_setTexture(var->foreground[2], little_house2, sfTrue);
    sfSprite_setTexture(var->foreground[3], medium_house, sfTrue);
    sfSprite_setTexture(var->foreground[4], big_house, sfTrue);
    sfSprite_setTexture(var->foreground[5], big_house, sfTrue);
    sfSprite_setTexture(var->foreground[6], big_house2, sfTrue);
    sfSprite_setTexture(var->foreground[7], barrier, sfTrue);
    sfSprite_setTexture(var->foreground[8], medium_house2, sfTrue);
}
