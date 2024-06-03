NAME = push_swap
SOURCE = main.c \
			checkin.c \
			fill_stack.c \
			swap.c \
			push.c \
			rotate.c \
			sort_utils.c \
			push_swap_util.c \
			prepare_stack.c \
			push_swap_tools.c
			
OBJS = $(SOURCE:.c=.o)

LDFLAGS= -L libft -l ft
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MAKEFLAGS = --no-print-directory

all:$(NAME)
	
$(NAME): $(OBJS)
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $^

clean:
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT:
