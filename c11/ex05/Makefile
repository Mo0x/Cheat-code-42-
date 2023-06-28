NAME = do-op
CC = cc
SRCS = ./srcs/main.c ./srcs/ft_atoi.c ./srcs/ft_op.c ./srcs/ft_check_zero.c
OBJS = $(patsubst %.c, %.o, $(SRCS))
INCDIRS = ./includes
CFLAGS = -Wall -Wextra -Werror -I $(INCDIRS)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
