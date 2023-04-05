NAME = minishell
INCLUDES_PATH	= ./includes
LIBFT_PATH = ./libft
LIB = libft/libft.a
CC	= cc
CFLAGS	= -Wall -Werror -Wextra -g3
VGSUPRESS	= --suppressions=readline.supp

SRCS = ./sources/minishell.c				\
		./sources/error_check.c				\
		./sources/error_messages.c			\
		./sources/start_shell.c				\
		./sources/get_next_line.c			\
		./sources/env_table/env.c			\
		./sources/env_table/env_utils.c		\
		./sources/env_table/insert_item.c	\
		./sources/env_table/get_item.c		\
		./sources/free_env.c				\
		./sources/tokenizer.c				\
		./sources/executor.c				\



OBJS	= $(SRCS:%.c=%.o)

all:	$(NAME) ${LIB}

$(NAME):	${LIB} $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $@ -L $(LIBFT_PATH) -lreadline -I $(INCLUDES_PATH) -I $(LIBFT_PATH) -lft

%.o:		%.c
			$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -I $(LIBFT_PATH) -o $@ -c $<

${LIB}:
			make -C libft

run:	$(NAME)
		./minishell

clean:
			$(MAKE) clean -C $(LIBFT_PATH)
			rm -f $(OBJS)

fclean:		clean
			$(MAKE) fclean -C $(LIBFT_PATH)
			rm -f $(NAME)

re:			fclean all

valgrind:	$(NAME)
			valgrind $(VGSUPRESS) -s --leak-check=full --show-leak-kinds=all \
			--track-origins=yes --trace-children=yes --log-fd=9 ./$(NAME) 9>memcheck.log

valgrind_track:	$(NAME)
			valgrind $(VGSUPRESS) -s --leak-check=full --show-leak-kinds=all \
			   --trace-children=yes --track-fds=yes --log-fd=9 ./$(NAME) 9>memcheck.log

.PHONY:		all clean fclean re