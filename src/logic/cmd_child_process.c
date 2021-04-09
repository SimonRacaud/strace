/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** cmd_child_process.c
*/

#include "app.h"

int cmd_child_process(args_t *args)
{
    if (ptrace(PT_TRACE_ME, 0, 0, 0) == -1) {
        perror("strace");
        return EXIT_ERROR;
    }
    raise(SIGSTOP);
    if (execvp(args->cmd[0], args->cmd) == -1) {
        perror("strace");
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}