/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main function
*/

#include "app.h"

int main(int argc, char **argv)
{
    args_t args;

    if (load_args(argc, argv, &args) != EXIT_SUCCESS) {
        return EXIT_ERROR;
    }
    // TODO
    clean_args(&args);
    return EXIT_SUCCESS;
}
