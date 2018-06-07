NAME = libft.a

SRC = ft_memset.c ft_bzero.c ft_memcpy.c

OBJ = *.o

FLAGS= gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(FLAGS) $(SRC) -c
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:	
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
