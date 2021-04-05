/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** clean_args.c
*/

#include "args.h"

void clean_args(args_t *args)
{
    if (args->attach_list) {
        pid_list_clean(args->attach_list);
    }
}