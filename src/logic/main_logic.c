/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** trace.c
*/

#include "app.h"

int main_logic(args_t *args)
{
    if (args->attach_list != NULL) {
        // TODO : handle -p flag
        // catch (CTRL + C) : signal
        // PTRACE_ATTACH
    }
    if (args->cmd != NULL) {
        if (tracer(args) != EXIT_SUCCESS)
            return EXIT_ERROR;
    }
    if (args->attach_list != NULL) {
        // TODO : handle -p flag
        // PTRACE_DETACH
    }
    return EXIT_SUCCESS;
}