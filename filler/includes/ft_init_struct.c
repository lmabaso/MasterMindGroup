#include "filler.h"

void	ft_init_struct(t_obj *input)
{
	input->bx = 0;
	input->by = 0;
	input->px = 0;
	input->py = 0;
	input->i = 0;
	input->j = 0;
	input->gameover = 0;
	input->isdone = 0;
	input->player = NULL;
	input->line = NULL;
	input->mypiece = '\0';
	input->oppiece = '\0';
	input->board = NULL;
	input->piece = NULL;
}