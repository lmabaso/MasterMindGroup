NAME = lmabaso.filler

SRC = includes/filler.c \
	  includes/ft_get_info.c \
	  includes/ft_makeboard.c \
	  includes/ft_find_close.c \
	  includes/ft_get_neighbours.c \
	  includes/ft_get_all_moves.c \
	  includes/ft_init_struct.c \
	  includes/main.c \
	  includes/ft_struct_op.c \
	  includes/ft_placement.c \
	  includes/ft_test.c \
	  includes/ft_lstsort.c \
	  includes/ft_maths.c \
	  includes/ft_get_physical_sqr.c \
	  includes/ft_free_stuff.c \

OBJ = *.o

FLAGS= gcc -g -Wall -Wextra -Werror -o

all: $(NAME)

$(NAME):
	@make -C includes/libft/ fclean && make -C includes/libft/
	@$(FLAGS) $(NAME) $(SRC) -L includes/libft/ -lft -I includes/libft/includes -I includes
clean:
	@make -C includes/libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C includes/libft fclean
	@rm -f $(NAME)

re: fclean all
