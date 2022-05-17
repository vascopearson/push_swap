SRCS = src/push_swap.c src/utils.c src/utils2.c src/errors.c src/free_all.c src/mid_point_help.c src/p_operations.c src/r_operations.c src/rr_operations.c src/s_operations.c src/sorting.c src/sorting_large.c src/sorting_large2.c

OBJS = $(SRCS:.c=.o)

BONUS = 

BONUS_OBJS = $(BONUS:.c=.o)

CC = gcc
RM = rm -f
LIBFT = libft
CFLAGS = -g -Wall -Wextra -Werror -I$(HEADER) -I$(LIBFT)
HEADER = inc

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
		$(MAKE) -C $(LIBFT)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT) -lft

clean: 
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus 
