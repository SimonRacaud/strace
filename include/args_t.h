/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** args_t.h
*/

#ifndef ARGS_T_H_
#define ARGS_T_H_

#include <ctype.h>
#include <stdbool.h>

typedef struct pid_list {
    struct pid_list *next;
    pid_t pid;
} pid_list_t;

typedef struct app_args {
    pid_list_t *attach_list;
    bool detailled;
    char **cmd;
    size_t line_length;
    char *binary;
} args_t;

#endif // ARGS_T_H_
