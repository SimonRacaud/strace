/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** tracer_process_syscall.c
*/

#include "app.h"

extern const struct s_syscall g_syscalls[];

static const syscall_t *getSyscallInfo(long long unsigned rax)
{
    for (size_t i = 0; g_syscalls[i].id != (unsigned long long)-1; i++) {
        if (g_syscalls[i].id == rax) {
            return &(g_syscalls[i]);
        }
    }
    return NULL;
}

static inline int print_syscall_name(const syscall_t *info)
{
    return fprintf(stderr, "%s(", info->name);
}

int tracer_process_syscall(args_t *args, user_regs_t *regs, pid_t child_pid)
{
    const syscall_t *info = getSyscallInfo(regs->rax);

    if (!info) {
        fprintf(stderr, "%s: syscall %llu not supported\n", args->binary,
            regs->rax);
        return EXIT_SUCCESS;
    }
    args->line_length = 0;
    args->line_length += print_syscall_name(info);
    if (regs->rax == READ_SYSCALL) {
        return trace_read(args, regs, child_pid, info);
    } else {
        if (syscall_show_args(args, regs, child_pid, info) != EXIT_SUCCESS)
            return EXIT_ERROR;
        if (syscall_show_return(args, regs, child_pid, info) != EXIT_SUCCESS)
            return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}