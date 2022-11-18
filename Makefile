NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
RM = rm -f

SRCS = ft_printf.c ft_convert.c ft_putstr.c ft_putnbr.c ft_puthexp.c ft_putchar.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
		$(CC) $(CFLAGS) $(SRCS)
		ar rcs $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re