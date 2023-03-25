NAME = minishell
INCLUDES_PATH	= ./includes
LIBFT_PATH = ./libft
LIB = libft/libft.a
CC	= cc
CFLAGS	= -Wall -Werror -Wextra -g3

SRCS = ./sources/minishell.c			\
		./sources/error_check.c			\
		./sources/error_messages.c		\
		./sources/start_shell.c			\


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

.PHONY:		all clean fclean re