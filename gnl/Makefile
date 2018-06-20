NAME = test_gnl

SRC = get_next_line.c

OBJ = *.o

FLAGS= gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C ../Libft/ fclean && make -C ../Libft/
	@$(FLAGS) -I ../Libft/includes -o get_next_line.o -c get_next_line.c
	@$(FLAGS) -I ../Libft/includes -o main.o -c main.c
	@clang -o $(NAME) main.o get_next_line.o -I ../Libft/includes -L../Libft/ -lft

clean:	
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
