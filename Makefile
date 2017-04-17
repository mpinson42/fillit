NAME = fillit

SRC = main.c ft_algo.c ft_resolv.c ft_pars.c ft_bzero.c ft_putstr.c ft_putchar.c ft_strsplit.c ft_strlen.c ft_memcpy.c ft_memset.c ft_strsub.c

FLAGS = -Wall -Wextra -Werror

SRC2 = main.o ft_algo.o ft_resolv.o ft_pars.o ft_bzero.o ft_putstr.o ft_putchar.o ft_strsplit.o ft_strlen.o ft_memcpy.o ft_memset.o ft_strsub.o

all: $(NAME)

$(NAME): $(SRC)
	gcc $(FLAGS) -c $(SRC)
	gcc -o $(NAME) $(SRC2)


clean:
	/bin/rm -f $(SRC2)

fclean: clean
		/bin/rm -rf $(NAME)

re: fclean all
