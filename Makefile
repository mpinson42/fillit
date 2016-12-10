
NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRC = ft_abs.c \
	  ft_assigne_list.c \
	  ft_check_piece.c \
	  ft_check_piece_extended.c \
	  ft_memset.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_resolv.c \
	  ft_resolv_extended.c \
	  ft_sqrt.c \
	  main.c \
	  ft_strsplit.c \

HEADER = fillit.h

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	gcc $(FLAGS) -I $(HEADER) -c $(SRC)
	gcc -o fillit $(OBJ)

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
