/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** tracer.c
*/

#include "app.h"

static inline void show_exit_status(int wstatus)
{
    fprintf(stderr, "+++ exited with %d +++\n", WEXITSTATUS(wstatus));
}

static int waitchild(pid_t pid, args_t *args)
{
    int status;

    if (wait4(pid, &status, 0, NULL) == -1) {
        perror(args->binary);
        return EXIT_ERROR;
    }
    if (WIFSTOPPED(status)) {
        return 0;
    } else if (WIFEXITED(status)) {
        show_exit_status(status);
        return 1;
    } else {
        return 1;
    }
}

static bool is_syscall(user_regs_t *regs, pid_t child_pid)
{
    long addr = ptrace(PTRACE_PEEKDATA, child_pid, regs->rip, NULL);

    if (addr == -1) {
        perror("strace");
        exit(EXIT_ERROR);
    }
    if ((addr & 0xFFFF) == 0x050F) {
        return true;
    }
    return false;
}

int processus_tracer(args_t *args, pid_t child_pid)
{
    int ret = EXIT_SUCCESS;
    user_regs_t regs;

    if (waitchild(child_pid, args) == 1) {
        fprintf(stderr, "child exited unexpectedly\n");
        return 84;
    }
    do {
        if (ptrace(PTRACE_GETREGS, child_pid, NULL, &regs) == -1) {
            perror(args->binary);
            return EXIT_ERROR;
        }
        if (is_syscall(&regs, child_pid)) {
            ret = tracer_process_syscall(args, &regs, child_pid);
        }
        if (ret != EXIT_SUCCESS)
            return ret;
        ptrace(PTRACE_SINGLESTEP, child_pid, NULL, NULL);
    } while (waitchild(child_pid, args) == 0);
    return EXIT_SUCCESS;
}

int trace_cmd(args_t *args)
{
    pid_t child_pid = fork();

    setvbuf(stdout, NULL, _IONBF, 0);
    if (child_pid == -1) {
        perror(args->binary);
        return EXIT_ERROR;
    } else if (child_pid == 0) {
        return cmd_child_process(args);
    } else {
        return processus_tracer(args, child_pid);
    }
}