/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** attach_processus.c
*/

#include "app.h"

static args_t *global_variable_not_really_hidden(args_t *args)
{
    static args_t *save = NULL;

    if (args) {
        save = args;
    }
    return save;
}

static void sig_handler(__attribute__((unused))int code)
{
    args_t *args = global_variable_not_really_hidden(NULL);

    detach_processus(args);
    exit(0); // TODO : exit smootly
}

static int attach_one_processus(args_t *args, pid_list_t *node)
{
    if (ptrace(PTRACE_ATTACH, node->pid, NULL, NULL) == -1) {
        perror(args->binary);
        return EXIT_ERROR;
    }
    fprintf(stderr, "%s: Process %d attached\n", args->binary, node->pid);
    if (processus_tracer(args, node->pid) != EXIT_SUCCESS) {
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

int attach_processus(args_t *args)
{
    if (signal(SIGINT, &sig_handler) == SIG_ERR) {
        return EXIT_ERROR;
    }
    global_variable_not_really_hidden(args);
    for (pid_list_t *ptr = args->attach_list; ptr != NULL; ptr = ptr->next) {
        if (attach_one_processus(args, ptr) != EXIT_SUCCESS) {
            return EXIT_ERROR;
        }
    }
    return EXIT_SUCCESS;
}