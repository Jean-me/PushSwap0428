# push_swap
NAME = push_swap.a
SRCS = main.c arg_check.c atoi.c push.c reverse_r.c rotate.c sort_two_or_three.c swap.c whisper_of_stacks.c
OBJS = $(SRCS:%.c=%.o)
# Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB_PRINTF_DIR = ft_printf
LIB_PRINTF = $(LIB_PRINTF_DIR)/libftprintf.a
# Header
HEADERS = push_swap.h

# Rules
all: $(NAME)

# Library target
$(LIB_PRINTF):
	$(MAKE) -C $(LIB_PRINTF_DIR)

$(NAME):	$(OBJS) $(LIB_PRINTF)
					$(CC) $(OBJS) $(LIB_PRINTF) -o $(NAME)

%.o: %.c $(HEADERS)
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS)
				$(MAKE) -C $(LIB_PRINTF_DIR) clean

fclean:	clean
				$(RM) $(NAME)
				$(MAKE) -C $(LIB_PRINTF_DIR) fclean

re:		fclean all

.PHONY:	all clean fclean re