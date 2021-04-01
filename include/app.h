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
#include <sys/ptrace.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>

#include <sys/syscall.h>

#include "args_t.h"
#include "strace.h"

typedef struct user_regs_struct user_regs_t;

#define EXIT_ERROR 84

// Args Management
int load_args(int argc, char **argv, args_t *args);
void clean_args(args_t *args);

// Logic
int cmd_child_process(args_t *args);

int main_logic(args_t *args);

int tracer(args_t *args);

int tracer_process_syscall(args_t *args, user_regs_t *regs, pid_t child_pid);
int syscall_show_return(
    args_t *args, user_regs_t *regs, pid_t child_pid, const syscall_t *info);
int syscall_show_args(
    args_t *args, user_regs_t *regs, pid_t child_pid, const syscall_t *info);

#endif // APP_H_
