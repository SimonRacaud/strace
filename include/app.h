/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** app.h
*/

#ifndef APP_H_
#define APP_H_

#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <sys/syscall.h>

#include "strace.h"
#include "args_t.h"

typedef struct user_regs_struct user_regs_t;

typedef struct print_reg {
    e_type type;
    t_printer func;
} print_reg_t;

typedef struct arg {
    e_type type;
    unsigned long long int value;
} arg_t;

#define EXIT_ERROR 84
#define READ_SYSCALL 0

// Args Management
int load_args(int argc, char **argv, args_t *args);
void clean_args(args_t *args);

// Logic
int cmd_child_process(args_t *args);

int main_logic(args_t *args);

int trace_cmd(args_t *args);
int processus_tracer(args_t *args, pid_t child_pid);

int tracer_process_syscall(args_t *args, user_regs_t *regs, pid_t child_pid);
int syscall_show_return(
    args_t *args, user_regs_t *regs, pid_t child_pid, const syscall_t *info);
int syscall_show_args(
    args_t *args, user_regs_t *regs, pid_t child_pid, const syscall_t *info);

int syscall_show_return_value(
    args_t *args, user_regs_t *regs, pid_t child_pid, const syscall_t *info);
long long register_find(int i, user_regs_t *regs);
// Special case : tracer
int trace_read(
    args_t *args, user_regs_t *regs, pid_t child_pid, const syscall_t *info);

// DISPLAY
int print_register(
    arg_t *val, pid_t child_pid, const user_regs_t *regs, const args_t *args);

int print_int(unsigned long long int reg,
    __attribute__((unused)) pid_t child_pid,
    __attribute__((unused)) const user_regs_t *regs,
    __attribute__((unused)) const args_t *args);
int print_pointer(unsigned long long int reg,
    __attribute__((unused)) pid_t child_pid,
    __attribute__((unused)) const user_regs_t *regs,
    __attribute__((unused)) const args_t *args);
int print_long(unsigned long long int reg,
    __attribute__((unused)) pid_t child_pid,
    __attribute__((unused)) const user_regs_t *regs,
    __attribute__((unused)) const args_t *args);
int print_ulong(unsigned long long int reg,
    __attribute__((unused)) pid_t child_pid,
    __attribute__((unused)) const user_regs_t *regs,
    __attribute__((unused)) const args_t *args);
int print_size_t(unsigned long long int reg,
    __attribute__((unused)) pid_t child_pid,
    __attribute__((unused)) const user_regs_t *regs,
    __attribute__((unused)) const args_t *args);
int print_ssize_t(unsigned long long int reg,
    __attribute__((unused)) pid_t child_pid,
    __attribute__((unused)) const user_regs_t *regs,
    __attribute__((unused)) const args_t *args);
int print_string(unsigned long long int reg, pid_t child_pid,
    __attribute__((unused)) const user_regs_t *regs,
    __attribute__((unused)) const args_t *args);

// specific case : print
int print_substring(unsigned long long int reg, pid_t child_pid, size_t size);

// Attach processus
int attach_processus(args_t *args);
int detach_processus(args_t *args);

#endif // APP_H_
