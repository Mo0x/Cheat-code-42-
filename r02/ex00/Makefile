NAME = rush-02
CC = cc
INCDIRS = ./includes
SRCS = ./srcs/main.c ./srcs/args_sorter.c ./srcs/dict_search.c ./srcs/dictionary_parser0.c ./srcs/dictionary_parser1.c ./srcs/ft_atoull.c ./srcs/ft_createstring.c ./srcs/ft_first_triplets.c ./srcs/ft_power.c ./srcs/ft_strlen.c ./srcs/str_cat_malloc.c ./srcs/ulltoa.c ./srcs/ft_split.c ./srcs/ft_strjoin.c ./srcs/ft_str_cleaner.c ./srcs/ft_hundred.c 
OBJS = $(patsubst %.c, %.o, $(SRCS))
CFLAGS = -Wall -Wextra -Werror -I $(INCDIRS)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $^

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
