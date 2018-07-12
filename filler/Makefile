NAME = lmabaso.filler

SRC = includes/filler.c \
	  includes/ft_get_info.c \
	  includes/ft_makeboard.c \
	  includes/ft_get_neighbours.c \
	  includes/ft_get_available_move.c \
	  includes/ft_get_physical_spr.c \
	  includes/ft_init_struct.c \
	  includes/main.c \
	  includes/ft_get_opponent_pieces.c \
	  includes/ft_struct_op.c \
	  includes/ft_placement.c \


OBJ = *.o

FLAGS= gcc -Wall -Wextra -Werror -o

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
