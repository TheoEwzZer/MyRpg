/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void create_house_collider(var_t *var)
{
    sfRectangleShape_setPosition(var->collider[0], (sfVector2f){1656, 1144});
    sfRectangleShape_setPosition(var->collider[26], (sfVector2f){864, 1000});
    sfRectangleShape_setPosition(var->collider[27], (sfVector2f){HEIGHT, 1000});
    sfRectangleShape_setPosition(var->collider[28], (sfVector2f){576, 1324});
    sfRectangleShape_setPosition(var->collider[29], (sfVector2f){252, 1432});
    sfRectangleShape_setPosition(var->collider[30], (sfVector2f){144, 1144});
    sfRectangleShape_setPosition(var->collider[31], (sfVector2f){288, 784});
    sfRectangleShape_setPosition(var->collider[32], (sfVector2f){468, 784});
    sfRectangleShape_setPosition(var->collider[34], (sfVector2f){864, 604});
    sfRectangleShape_setPosition(var->collider[35], (sfVector2f){900, 718});
    sfRectangleShape_setSize(var->collider[0], (sfVector2f){144, 150});
    sfRectangleShape_setSize(var->collider[26], (sfVector2f){216, 186});
    sfRectangleShape_setSize(var->collider[27], (sfVector2f){36, 150});
    sfRectangleShape_setSize(var->collider[28], (sfVector2f){144, 150});
    sfRectangleShape_setSize(var->collider[29], (sfVector2f){144, 150});
    sfRectangleShape_setSize(var->collider[30], (sfVector2f){180, 150});
    sfRectangleShape_setSize(var->collider[31], (sfVector2f){180, 186});
    sfRectangleShape_setSize(var->collider[32], (sfVector2f){72, 150});
    sfRectangleShape_setSize(var->collider[34], (sfVector2f){252, 114});
    sfRectangleShape_setSize(var->collider[35], (sfVector2f){180, 36});
}

void set_foreground_position(var_t *var)
{
    var->foreground = malloc(sizeof(sfSprite *) * 9);
    for (unsigned int i = 0; i < 9; i++)
        var->foreground[i] = sfSprite_create();
    sfSprite_setPosition(var->foreground[0], (sfVector2f){1656, 1114});
    sfSprite_setPosition(var->foreground[1], (sfVector2f){252, 1402});
    sfSprite_setPosition(var->foreground[2], (sfVector2f){576, 1294});
    sfSprite_setPosition(var->foreground[3], (sfVector2f){144, 1114});
    sfSprite_setPosition(var->foreground[4], (sfVector2f){288, 754});
    sfSprite_setPosition(var->foreground[5], (sfVector2f){864, 574});
    sfSprite_setPosition(var->foreground[6], (sfVector2f){864, 970});
    sfSprite_setPosition(var->foreground[7], (sfVector2f){1058, 790});
    sfSprite_setPosition(var->foreground[8], (sfVector2f){1440, 718});
}

void create_foreground(var_t *var)
{
    sfTexture *little_house = CREATE_FROM_FILE("assets/map/little_house.png");
    sfTexture *little_house2 = CREATE_FROM_FILE("assets/map/little_house2.png");
    sfTexture *medium_house = CREATE_FROM_FILE("assets/map/medium_house.png");
    sfTexture *big_house = CREATE_FROM_FILE("assets/map/big_house.png");
    sfTexture *big_house2 = CREATE_FROM_FILE("assets/map/big_house2.png");
    sfTexture *barrer = CREATE_FROM_FILE("assets/map/barrer.png");
    sfTexture *medium_house2 = CREATE_FROM_FILE("assets/map/medium_house2.png");

    set_foreground_position(var);
    sfSprite_setTexture(var->foreground[0], little_house, sfTrue);
    sfSprite_setTexture(var->foreground[1], little_house, sfTrue);
    sfSprite_setTexture(var->foreground[2], little_house2, sfTrue);
    sfSprite_setTexture(var->foreground[3], medium_house, sfTrue);
    sfSprite_setTexture(var->foreground[4], big_house, sfTrue);
    sfSprite_setTexture(var->foreground[5], big_house, sfTrue);
    sfSprite_setTexture(var->foreground[6], big_house2, sfTrue);
    sfSprite_setTexture(var->foreground[7], barrer, sfTrue);
    sfSprite_setTexture(var->foreground[8], medium_house2, sfTrue);
}
