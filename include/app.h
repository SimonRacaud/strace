/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** app.h
*/

#ifndef APP_H_
#define APP_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "args_t.h"

#define EXIT_ERROR 84;



// Args Management
int load_args(int argc, char **argv, args_t *args);
void clean_args(args_t *args);

//

#endif // APP_H_
