/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void create_value(FILE *file)
{
    const char *str = "MAX_FIREBALL: 3\n";

    fwrite(str, sizeof(char), 16, file);
    str = "MAX_LEAVES: 50\n";
    fwrite(str, sizeof(char), 15, file);
    str = "MAX_PARTICLES: 10\n";
    fwrite(str, sizeof(char), 18, file);
}

void create_dialog(FILE *file)
{
    const char *str = "BLACKSMITH_DIALOG: Take this armor !\n";

    fwrite(str, sizeof(char), 37, file);
    str = "BLACKSMITH_DIALOG2: Attack enemies who\\nare higher up !\n";
    fwrite(str, sizeof(char), 56, file);
    str = "TUTORIAL_BLACKSMITH: Left click or Space to attack !\\n";
    fwrite(str, sizeof(char), 54, file);
    str = "E to open inventory !\\nRight click on the potion to use it !\n";
    fwrite(str, sizeof(char), 61, file);
    str = "PRISCILLA_DIALOG: We need you !\\nTalk to the blacksmith !\n";
    fwrite(str, sizeof(char), 58, file);
    str = "PRISCILLA_DIALOG2: Attack enemies who\\nare higher up !\n";
    fwrite(str, sizeof(char), 55, file);
    str = "BOB_DIALOG1: Talk to me later !\n";
    fwrite(str, sizeof(char), 32, file);
    str = "BOB_DIALOG2: Now you need to defeat the boss\\n";
    fwrite(str, sizeof(char), 46, file);
    str = "Go at the bottom of the map !\n";
    fwrite(str, sizeof(char), 30, file);
}

void create_config(const char *file_name)
{
    FILE *file = fopen(file_name, "rb");

    if (file) {
        fclose(file);
        return;
    }
    file = fopen(file_name, "wb");
    if (!file)
        return;
    create_dialog(file);
    create_value(file);
    fclose(file);
}
