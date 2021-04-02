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
        if (attach_processus(args) != EXIT_SUCCESS) {
            return EXIT_ERROR;
        }
    }
    if (args->cmd != NULL) {
        if (trace_cmd(args) != EXIT_SUCCESS)
            return EXIT_ERROR;
    }
    if (args->attach_list != NULL) {
        if (detach_processus(args) != EXIT_SUCCESS) {
            return EXIT_ERROR;
        }
    }
    return EXIT_SUCCESS;
}