/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** arg_pid_list.c
*/

#include "args.h"

int push_pid_value(args_t *args, const char *value)
{
    pid_t val;

    for (size_t i = 0; value[i] != '\0'; i++) {
        if (value[i] < '0' || value[i] > '9') {
            fprintf(
                stderr, "%s: Invalid process id: '%s'\n", args->binary, value);
            return EXIT_ERROR;
        }
    }
    val = strtoul(value, NULL, 0xA);
    if (val == 0) {
        fprintf(stderr, "%s: Invalid process id: '%s'\n", args->binary, value);
        return EXIT_ERROR;
    }
    return push_pid(&(args->attach_list), val);
}

int push_pid(pid_list_t **list, pid_t pid)
{
    pid_list_t *last = *list;

    if (list == NULL || *list == NULL) {
        *list = malloc(sizeof(pid_list_t));
        if (!(*list))
            return EXIT_ERROR;
        (*list)->pid = pid;
        (*list)->next = NULL;
    } else {
        while (last->next != NULL)
            last = last->next;
        last->next = malloc(sizeof(pid_list_t));
        if (!last->next)
            return EXIT_ERROR;
        last->next->pid = pid;
        last->next->next = NULL;
    }
    return EXIT_SUCCESS;
}

void pid_list_clean(pid_list_t *list)
{
    pid_list_t *ptr = list;
    pid_list_t *next = NULL;

    if (!list)
        return;
    do {
        next = ptr->next;
        free(ptr);
        ptr = next;
    } while (ptr);
}