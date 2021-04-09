/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** syscall_show_args.c
*/

#include "app.h"

long long register_find(int i, user_regs_t *regs)
{
    switch (i) {
        case 0: return regs->rdi;
        case 1: return regs->rsi;
        case 2: return regs->rdx;
        case 3: return regs->r10;
        case 4: return regs->r8;
        case 5: return regs->r9;
        default: return 0;
    }
}

static int print_syscall_params(args_t *args, struct s_syscall_arg sys_arg,
    pid_t child_pid, unsigned long long reg_value)
{
    int size;
    arg_t arg;

    if (!sys_arg.custom) {
        arg.type = sys_arg.printer.type;
        arg.value = reg_value;
        size = print_register(&arg, child_pid, NULL, args);
    } else {
        size = sys_arg.printer.callback(reg_value, child_pid, NULL, args);
    }
    return size;
}

int syscall_show_args(
    args_t *args, user_regs_t *regs, pid_t child_pid, const syscall_t *info)
{
    unsigned long long reg_value;
    int size;

    for (size_t i = 0; i < info->argc; i++) {
        if (i != 0) {
            args->line_length += fprintf(stderr, ", ");
        }
        reg_value = register_find(i, regs);
        size = print_syscall_params(args, info->args[i], child_pid, reg_value);
        if (size == -1)
            return EXIT_ERROR;
        args->line_length += size;
    }
    return EXIT_SUCCESS;
}