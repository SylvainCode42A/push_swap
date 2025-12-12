NAME = push_swap.a

SRCS = 	set_tab.c \
		strjoin_space.c \
		ft_push_swap.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		swap.c \
		simple.c \
		medium.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes -I../libft/includes

LIBFT = ../libft/libft.a
PRINTF = ../ft_printf/libftprintf.a
LIBS = $(LIBFT) $(PRINTF)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all