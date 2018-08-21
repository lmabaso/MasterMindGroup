NAME0 = push_swap

NAME1 = checker

SRC = src/ft_verify.c \
	  src/ft_init_stack.c \
	  src/ft_stack_rot_op.c \
	  src/ft_stack_sw_op.c \
	  src/ft_stack_push_op.c \
	  src/ft_check.c \
	  src/ft_minmax.c \
	  src/ft_decisions.c \
	  src/ft_sort.c \
	  src/ft_lstsort.c \
	  src/ft_test.c \
	  src/ft_update.c \

OBJ = *.o

FLAGS= gcc -Wall -Wextra -Werror -o

all: $(NAME0) $(NAME1)

$(NAME0):
	@make -C libft/ fclean && make -C libft/
	@$(FLAGS) $(NAME0) $(SRC) src/push_swap.c -L libft/ -lft -I libft/includes -I includes
	
$(NAME1):
	@make -C libft/ fclean && make -C libft/
	@$(FLAGS) $(NAME1) $(SRC) src/checker.c -L libft/ -lft -I libft/includes -I includes

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME1)
	@rm -f $(NAME0)

re: fclean all
