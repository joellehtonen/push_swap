NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs
CC = gcc
LIBFT = ./library/libft/libft.a
PRINTF = ./library/printf/libftprintf.a
SOURCES =	main.c \
			check_input.c \
			check_order.c \
			fill_stack.c \
			push.c \
			reverse_rotate.c \
			rotate.c \
			swap.c \
			sort_stack.c
OBJECTS = $(SOURCES:.c=.o)
HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c -I $(HEADER) $< -o $@

clean: 
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re