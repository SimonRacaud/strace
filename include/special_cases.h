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

/**
 * @brief Print arguments of stat function when caught
 *
 * @param reg The value of the actual register
 * @param child_pid  The pid of the child process being traced - UNUSED
 * @param regs The registers of the current syscall - UNUSED
 * @param args The (strace) program arguments - UNUSED
 *
 * @return The number of characters written on the error output
 */
int spe_stat(unsigned long long int reg, pid_t child_pid,
    const struct user_regs_struct *regs, const args_t *args);

#endif // STRACE_SPECIAL_CASES_H