NAME = fillit

SRC = ./srcs/main.c ./srcs/ft_algo.c ./srcs/ft_resolv.c ./srcs/ft_pars.c

FLAGS = -Wall -Wextra -Werror

SRC2 = main.o ft_algo.o ft_resolv.o ft_pars.o

all: $(NAME)

$(NAME): $(SRC)
	@echo "mpinson" > auteur
	@make -C ./libft all
	@cp ./libft/libft.a ./lib
	gcc $(FLAGS) -I ./include/ -L ./lib -lft -o $(NAME) $(SRC)


clean:
	/bin/rm -f $(SRC2)
	@make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm lib/libft.a
	@make -C ./libft fclean

re: fclean all