/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** syscall_show_return.c
*/

#include "app.h"

static inline int error(const char *bin)
{
    perror(bin);
    return EXIT_ERROR;
}

static inline void print_padding(args_t *args)
{
    fprintf(stderr, ")");
    for (size_t i = args->line_length + 1; i < 40; i++) {
        fprintf(stderr, " ");
    }
    fprintf(stderr, " = ");
}

int syscall_show_return_value(
    args_t *args, user_regs_t *regs, pid_t child_pid, const syscall_t *info)
{
    int status = EXIT_SUCCESS;
    arg_t arg = {.type = info->retval, .value = 0};

    if (ptrace(PTRACE_GETREGS, child_pid, NULL, regs) == -1)
        return error(args->binary);
    arg.value = regs->rax;
    print_padding(args);
    if (errno_handler(&arg) == EXIT_FAILURE) {
        status = print_register(&arg, child_pid, regs, args);
    }
    fprintf(stderr, "\n");
    return status != -1 ? EXIT_SUCCESS : EXIT_ERROR;
}

int syscall_show_return(
    args_t *args, user_regs_t *regs, pid_t child_pid, const syscall_t *info)
{
    if (info->noreturn == false) {
        if (regs->rax == __NR_exit_group || regs->rax == __NR_exit
            || regs->rax == __NR_pkey_free) {
            print_padding(args);
            fprintf(stderr, "?\n");
            return EXIT_SUCCESS;
        }
        if (ptrace(PTRACE_SINGLESTEP, child_pid, NULL, NULL) == -1)
            return error(args->binary);
        if (waitpid(child_pid, 0, 0) == -1)
            return error(args->binary);
        return syscall_show_return_value(args, regs, child_pid, info);
    } else {
        fprintf(stderr, ")\n");
    }
    return EXIT_SUCCESS;
}