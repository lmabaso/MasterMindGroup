NAME =	lem-in

SRC =	src/main.c \
		src/ft_lstappend.c \
		src/ft_lstseach.c \
		src/ft_test.c \
		src/ft_search_path.c \
		src/ft_maths.c \

OBJ = *.o

FLAGS= gcc -Wall -Wextra -Werror -o

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@$(FLAGS) $(NAME) $(SRC) -L libft/ -lft -I libft/includes -I includes

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all
