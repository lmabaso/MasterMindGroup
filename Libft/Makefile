NAME = libft.a

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
      ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_atoi.c ft_strncmp.c \
      ft_isspace.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c

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
