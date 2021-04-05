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
    int status = EXIT_SUCCESS;

    if (load_args(argc, argv, &args) != EXIT_SUCCESS) {
        return EXIT_ERROR;
    }
    status = main_logic(&args);
    clean_args(&args);
    return status;
}
