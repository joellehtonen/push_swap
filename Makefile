NAME = push_swap
BONUS_NAME = checker
CFLAGS = -Wall -Wextra -Werror -g
CC = cc
LIBFT_DIR = ./library/libft/
LIBFT = $(LIBFT_DIR)/libft.a
GNL_DIR = ./library/get_next_line/
SRC_DIR = .
MAIN_SOURCES = 		main.c
COMMON_SOURCES =	exit.c \
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
BONUS_SOURCES = push_swap_checker_bonus.c \
				$(GNL_DIR)get_next_line.c \
				$(GNL_DIR)get_next_line_utils.c
MAIN_OBJECTS = $(MAIN_SOURCES:.c=.o)
COMMON_OBJECTS = $(COMMON_SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)
HEADER = push_swap.h

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(MAIN_OBJECTS) $(COMMON_OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(MAIN_OBJECTS) $(COMMON_OBJECTS) -L$(LIBFT_DIR) -lft

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_NAME): $(BONUS_OBJECTS) $(COMMON_OBJECTS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJECTS) $(COMMON_OBJECTS) -L$(LIBFT_DIR) -lft

bonus: $(LIBFT) $(BONUS_NAME)

clean: 
	rm -f $(MAIN_OBJECTS) $(COMMON_OBJECTS) $(BONUS_OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
