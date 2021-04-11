/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** trace_read.c
*/

#include "app.h"

static int error(const char *bin)
{
    perror(bin);
    return EXIT_ERROR;
}

static int show_read_string_content(
    args_t *args, pid_t child_pid, size_t *size, unsigned long long reg_value)
{
    user_regs_t post_syscall_regs = {0};

    if (ptrace(PTRACE_GETREGS, child_pid, NULL, &post_syscall_regs) == -1)
        return error(args->binary);
    *size = print_substring(reg_value, child_pid, post_syscall_regs.rax);
    return EXIT_SUCCESS;
}

static int show_args(
    const syscall_t *info, args_t *args, user_regs_t *regs, pid_t child_pid)
{
    static size_t idx = 0;
    unsigned long long reg_value;
    arg_t arg;
    size_t size;

    reg_value = register_find(idx, regs);
    if (idx != 1) {
        arg.type = info->args[idx].printer.type;
        arg.value = reg_value;
        size = print_register(&arg, child_pid, regs, args);
    } else {
        if (show_read_string_content(args, child_pid, &size, reg_value))
            return EXIT_ERROR;
    }
    args->line_length += size;
    if (idx != 2)
        args->line_length += fprintf(stderr, ", ");
    if (++idx == 3)
        idx = 0;
    return EXIT_SUCCESS;
}

int trace_read(
    args_t *args, user_regs_t *regs, pid_t child_pid, const syscall_t *info)
{
    if (show_args(info, args, regs, child_pid) != EXIT_SUCCESS)
        return EXIT_ERROR;
    if (execute_syscall(child_pid, args, true) != EXIT_SUCCESS)
        return EXIT_ERROR;
    for (size_t i = 0; i < 2; i++) {
        if (show_args(info, args, regs, child_pid) != EXIT_SUCCESS)
            return EXIT_ERROR;
    }
    if (syscall_show_return_value(args, regs, child_pid, info) != EXIT_SUCCESS)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}