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
        case 0:
            return regs->rdi;
        case 1:
            return regs->rsi;
        case 2:
            return regs->rdx;
        case 3:
            return regs->r10;
        case 4:
            return regs->r8;
        case 5:
            return regs->r9;
        default:
            return 0;
    }
}

int syscall_show_args(
    args_t *args, user_regs_t *regs, pid_t child_pid, const syscall_t *info)
{
    unsigned long long reg_value;

    for (size_t i = 0; i < info->argc; i++) {
        if (i != 0) {
            fprintf(stderr, ", ");
        }
        reg_value = register_find(i, regs);
        // TODO : show register value
        fprintf(stderr, "%llu", reg_value); // TEMP
    }
    return EXIT_SUCCESS;
}