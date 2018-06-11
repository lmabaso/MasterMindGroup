NAME = libft.a

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
      ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c

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
