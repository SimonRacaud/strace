/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** usage.c
*/

#include "args.h"

int usage(char *bin)
{
    printf("Usage: %s [-hs] [-p PID]\n\n", bin);
    printf("\t-h\tusages\n");
    printf("\nStartup:\n");
    printf("\t-p PID\ttrace process with process id PID, may be repeated\n");
    printf("\nOutput format:\n");
    printf("\t-s\tshow detailled arguments\n");
    return EXIT_SUCCESS;
}