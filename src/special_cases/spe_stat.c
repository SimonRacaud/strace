/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** spe_stat.c
*/

#include "app.h"

static const size_t MAX_SIZE = 32; // TODO ask simon what it is for

static int print_struct_stat(
    unsigned long long int reg, pid_t child_pid, size_t *idx)
{
    size_t size = 0;
    long c = -1;

    ptrace(PTRACE_SINGLESTEP, child_pid, NULL, NULL);

    for (*idx = 0; (*idx) < MAX_SIZE; (*idx)++) {
        errno = 0;
        c = ptrace(PTRACE_PEEKDATA, child_pid, reg + (*idx), NULL);
        if (c == -1 && errno)
            return -1;
        size += fprintf(stderr, "%lu\n", c);
    }
    return size;
}

int spe_stat(unsigned long long int reg,
    __attribute__((unused)) pid_t child_pid,
    __attribute__((unused)) const struct user_regs_struct *regs,
    __attribute__((unused)) const args_t *args)
{
    size_t size = 0;
    size_t idx = 0;

    print_struct_stat(reg, child_pid, &idx);
    if (idx == MAX_SIZE - 1) {
        size += fprintf(stderr, "...");
    }

    //    size = fprintf(stderr, "%lu\n", ((struct stat *) reg)->st_dev);

    return size;
}