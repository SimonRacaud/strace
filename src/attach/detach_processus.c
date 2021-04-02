/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** detach_processus.c
*/

#include "app.h"

int detach_processus(args_t *args)
{
    if (args->detached == true) {
        return EXIT_SUCCESS;
    }
    for (pid_list_t *ptr = args->attach_list; ptr != NULL; ptr = ptr->next) {
        if (ptrace(PTRACE_DETACH, ptr->pid, NULL, NULL) == -1) {
            perror(args->binary);
            return EXIT_ERROR;
        }
        fprintf(stderr, "%s: Process %d detached\n", args->binary, ptr->pid);
    }
    args->detached = true;
    return EXIT_SUCCESS;
}