NAME = libft.a
INCDIRS = ./includes
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(INCDIRS)
CFILES = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = $(patsubst %.c,%.o,$(CFILES))

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
