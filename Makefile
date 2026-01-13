NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -Ift_printf
SRC = main.c \
	  ft_push_swap.c \
      utils_fonctions_1.c \
      utils_fonctions_2.c \
	  utils_fonctions_3.c \
      simple.c \
      modes_utils.c \
      medium.c \
      complex.c \
      swap.c \
      rotate.c \
      reverse_rotate.c \
      push.c
OBJ = $(SRC:.c=.o)
PRINTF = ft_printf/printf.a

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(PRINTF)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C ft_printf fclean

re: fclean all