#include "filler.h"

void	ft_init_struct(t_obj *input)
{
	input->bx = 0;
	input->by = 0;
	input->px = 0;
	input->py = 0;
	input->i = 0;
	input->j = 0;
	input->isdone = 0;
	input->player = NULL;
	input->line = NULL;
	input->mypiece = '\0';
	input->oppiece = '\0';
	input->board = NULL;
	input->piece = NULL;
	input->aboard = NULL;
	input->realpiece = NULL;
	input->moves = NULL;
	ft_put_to_co(&input->bestmove, 0, 0);
}
