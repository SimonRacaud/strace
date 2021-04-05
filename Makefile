##
## EPITECH PROJECT, 2021
## Project_2021
## File description:
## Project makefile
##

DSRC	=	./src/

SRC_FILES	=	main.c				\
				strace.c			\
				args/load_args.c	\
				args/clean_args.c	\
				args/arg_pid_list.c	\
				args/usage.c		\
				logic/main_logic.c						\
				logic/cmd_child_process.c				\
				logic/tracer/tracer.c					\
				logic/tracer/tracer_process_syscall.c	\
				logic/tracer/syscall_show_args.c		\
				logic/tracer/syscall_show_return.c		\
				logic/display/print_register.c			\
				logic/display/print_int.c				\
				logic/display/print_long.c				\
				logic/display/print_pointer.c			\
				logic/display/print_size_t.c			\
				logic/display/print_string.c			\
				attach/attach_processus.c				\
				attach/detach_processus.c				\

SRC	=	$(addprefix $(DSRC), $(SRC_FILES))

OBJ	=	$(SRC:.c=.o)

NAME	=	strace

CFLAGS	+= -std=gnu11 -Wall -Wextra -W $(INCLUDE)

INCLUDE = -I./include

debug: CFLAGS += -g
debug: all

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) && \
		$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) "$(NAME)\n"$(DEFAULT) || \
		$(ECHO) $(BOLD_T)$(RED_C)"[✘] "$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) "$(NAME)\n"$(DEFAULT)

clean:
	rm -f  $(OBJ)
	rm -f *.gcda
	rm -f *.gcno

fclean:	clean
	rm -f $(NAME)

re:	fclean all

#tests_run:
#gcc -o $(NAME) $(SRC_UT) -I./include -L./lib/my -lmy -lcriterion --coverage && ./$(NAME)

.PHONY :        clean fclean re

ECHO	=	/bin/echo -e
DEFAULT	=	"\e[0m"
BOLD_T	=	"\e[1m"
DIM_T	=	"\e[2m"
UNDLN_T	=	"\e[4m"
BLACK_C	=	"\e[30m"
RED_C	=	"\e[31m"
GREEN_C	=	"\e[32m"
YELLO_C	=	"\e[33m"
BLUE_C	=	"\e[34m"
MAGEN_C	=	"\e[35m"
CYAN_C	=	"\e[36m"
WHITE_C	=	"\e[97m"
DEFAULT_C	=	"\e[39m"
LINE_RETURN	=	$(ECHO) ""
