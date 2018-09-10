NAME	=	asm

SRC		= 	asm_src/main.c \
			asm_src/ft_init.c \
			asm_src/ft_free_stuff.c \
			asm_src/ft_error_check.c \
			asm_src/ft_lst_funt.c \
			asm_src/ft_read_proc.c \
			asm_src/ft_make_encode.c \
			asm_src/ft_alloc_size.c \
			asm_src/ft_write_op.c \
			asm_src/ft_make_header.c \
			
OJB		= 	*.o

FLAGS	=	gcc -Wall -Wextra -Werror -o

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@$(FLAGS) $(NAME) $(SRC) -L libft/ -lft -I libft/includes -I includes

clean:
	@make -C libft clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re:	fclean all
