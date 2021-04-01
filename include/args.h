/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** args.h
*/

#ifndef ARGS_H_
#define ARGS_H_

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "args_t.h"

#ifndef EXIT_ERROR
    #define EXIT_ERROR 84;
#endif

int push_pid_value(args_t *args, const char *value);
int push_pid(pid_list_t **list, pid_t pid);
void pid_list_clean(pid_list_t *list);
int usage(char *bin);

#endif // ARGS_H_
