/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** app.h
*/

#ifndef APP_H_
#define APP_H_

typedef struct app_args {
    pid_t *attach_list;
    size_t attach_list_size;
    bool detailled;
} args_t;


#endif // APP_H_
