NAME = printf.a

SRCS = ft_printf.c \
       utiles/ft_putchar.c \
       utiles/ft_putstr.c \
       utiles/ft_putnbr.c \
       utiles/ft_putnbr_unsigned.c \
       utiles/ft_puthex_upper.c \
       utiles/ft_puthex_lower.c \
       utiles/ft_putptr.c

OBJS = $(SRCS:.c=.o)

CC = cc

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