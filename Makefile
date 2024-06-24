NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -g
CC = gcc
LIBFT_DIR = ./library/libft/
LIBFT = $(LIBFT_DIR)/libft.a
SOURCES =	main.c \
			check_input.c \
			check_order.c \
			cost.c \
			index.c \
			fill_stack.c \
			final_push.c \
			lst_functions.c \
			push.c \
			reverse_rotate.c \
			rotate.c \
			swap.c \
			sort_chooser.c \
			sort_larger_stack.c
OBJECTS = $(SOURCES:.c=.o)
HEADER = push_swap.h

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -L$(LIBFT_DIR) -lft

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re