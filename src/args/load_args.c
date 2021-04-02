/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** arg.c
*/

#include "args.h"

static void init_args(args_t *args, char *bin)
{
    args->attach_list = NULL;
    args->detailled = false;
    args->cmd = NULL;
    args->binary = bin;
    args->detached = false;
}

static int invalid_arg(void)
{
    if (optopt == 'c') {
        fprintf(stderr, "Option -%c requires an argument.\n", optopt);
    } else if (isprint(optopt)) {
        fprintf(stderr, "Unknown option `-%c'.\n", optopt);
    }
    return EXIT_ERROR;
}

static int process_flag(char **argv, args_t *args, int opt)
{
    switch (opt) {
        case 'h':
            return usage(argv[0]);
            break;
        case 's':
            args->detailled = true;
            break;
        case 'p':
            if (push_pid_value(args, optarg) != EXIT_SUCCESS)
                return EXIT_ERROR;
            break;
        default:
            return invalid_arg();
    }
    return EXIT_SUCCESS;
}

static int invalid_amount_arguments(const char *bin)
{
    fprintf(stderr,
            "%s: must have PROG [ARGS] or -p PID\n"
            "Try 'strace -h' for more information.\n",
            bin);
    return EXIT_ERROR;
}

int load_args(int argc, char **argv, args_t *args)
{
    int opt = getopt(argc, argv, "hsp:");

    if (argc < 2) {
        return invalid_amount_arguments(argv[0]);
    }
    init_args(args, argv[0]);
    while (opt != -1 && opt != '?') {
        if (process_flag(argv, args, opt) != EXIT_SUCCESS)
            return EXIT_ERROR;
        opt = getopt(argc, argv, "hsp:");
    }
    if (argv[optind] != NULL) {
        args->cmd = &argv[optind];
    } else if (args->attach_list == NULL) {
        return invalid_amount_arguments(argv[0]);
    }
    return EXIT_SUCCESS;
}
