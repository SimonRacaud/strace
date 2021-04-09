/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** spe_stat.c
*/

#include "app.h"

static inline int print_file_type(dev_t st_mode, bool *is_dir_file)
{
    switch (st_mode & S_IFMT) {
        case S_IFBLK: return fprintf(stderr, "S_IFBLK");
        case S_IFCHR: return fprintf(stderr, "S_IFCHR");
        case S_IFDIR: *is_dir_file = true; return fprintf(stderr, "S_IFDIR");
        case S_IFIFO: return fprintf(stderr, "S_IFIFO");
        case S_IFLNK: return fprintf(stderr, "S_IFLNK");
        case S_IFREG: *is_dir_file = true; return fprintf(stderr, "S_IFREG");
        case S_IFSOCK: return fprintf(stderr, "S_IFSOCK");
    }
    return fprintf(stderr, "?");
}

static int print_file_permissions(
    unsigned long long int reg, pid_t child_pid, bool *is_dir_file)
{
    size_t size = 0;
    long my_st_mode = -1;
    size_t offset_elem = offsetof(struct stat, st_mode);

    my_st_mode = ptrace(PTRACE_PEEKDATA, child_pid, reg + offset_elem, NULL);
    if (my_st_mode == -1 && errno)
        return -1;
    size += fprintf(stderr, "st_mode=");
    size += print_file_type(my_st_mode, is_dir_file);
    fprintf(stderr, "|0%lo", my_st_mode & 07777);
    return size;
}

static int print_more_info(
    unsigned long long int reg, pid_t child_pid, const bool is_dir_file)
{
    size_t size = 0;
    long my_variable = -1;
    size_t offset_elem = 0;

    offset_elem = (is_dir_file) ? offsetof(struct stat, st_size)
                                : offsetof(struct stat, st_rdev);
    my_variable = ptrace(PTRACE_PEEKDATA, child_pid, reg + offset_elem, NULL);
    if (my_variable == -1 && errno)
        return -1;
    size += (is_dir_file) ? fprintf(stderr, "st_size=%lu", my_variable)
                          : fprintf(stderr,
                              "st_rdev=makedev(0x%x, 0x%x)",
                              major(my_variable),
                              minor(my_variable));
    return size;
}

static int print_struct_stat(unsigned long long int reg, pid_t child_pid)
{
    size_t size = 0;
    bool is_dir_file = false;

    errno = 0;
    size += print_file_permissions(reg, child_pid, &is_dir_file);
    size += fprintf(stderr, ", ");
    errno = 0;
    size += print_more_info(reg, child_pid, is_dir_file);
    size += fprintf(stderr, ", ");
    return size;
}

int spe_stat(unsigned long long int reg,
    __attribute__((unused)) pid_t child_pid,
    __attribute__((unused)) const struct user_regs_struct *regs,
    const args_t *args)
{
    size_t size = 0;

    execute_syscall(child_pid, args, true);
    size += fprintf(stderr, "{");
    size += print_struct_stat(reg, child_pid);
    size += fprintf(stderr, "...}");
    return size;
}