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

int syscall_show_return(
    args_t *args, user_regs_t *regs, pid_t child_pid, const syscall_t *info)
{
    if (info->noreturn == false) {
        if (regs->rax == __NR_exit_group || regs->rax == __NR_exit
            || regs->rax == __NR_pkey_free) {
            fprintf(stderr, ") = ?\n");
            return EXIT_SUCCESS;
        }
        if (ptrace(PTRACE_SINGLESTEP, child_pid, NULL, NULL) == -1)
            return error(args->binary);
        if (waitpid(child_pid, 0, 0) == -1)
            return error(args->binary);
        if (ptrace(PTRACE_GETREGS, child_pid, NULL, regs) == -1)
            return error(args->binary);
        // TODO : print value
        // info->retval : return type
        // args->detailled : detailled mode
        fprintf(stderr, ") = %lld\n", regs->rax); // TEMP
    } else {
        fprintf(stderr, ")\n");
    }
    return EXIT_SUCCESS;
}