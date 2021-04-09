/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** execute_syscall.c
*/

#include "app.h"

int execute_syscall(
    pid_t child_pid, const args_t *args, const bool print_error)
{
    if (ptrace(PTRACE_SINGLESTEP, child_pid, NULL, NULL) == -1) {
        if (print_error)
            perror(args->binary);
        return EXIT_ERROR;
    }
    if (waitpid(child_pid, 0, 0) == -1) {
        if (print_error)
            perror(args->binary);
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}