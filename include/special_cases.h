/*
** EPITECH PROJECT, 2021
** special_cases.h
** File description:
** functions to print specific syscalls informations
*/

#ifndef STRACE_SPECIAL_CASES_H
#define STRACE_SPECIAL_CASES_H

#include "strace.h"
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <stddef.h>

int spe_stat(unsigned long long int reg, pid_t child_pid,
    const struct user_regs_struct *regs, const args_t *args);

#endif // STRACE_SPECIAL_CASES_H