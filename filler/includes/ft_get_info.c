#include "filler.h"

void	ft_get_info(t_obj *input)
{
	char **tmp;

	if (ft_strncmp(input->line, "$$$ exec ", 9) == 0)
	{
		input->player = ft_strsub(input->line, 9, 2);
		input->mypiece = (ft_strcmp(input->player, "p1") == 0) ? 'O' : 'X';
		input->oppiece = (ft_strcmp(input->player, "p1") == 0) ? 'X' : 'O';
	}
	if (ft_strncmp(input->line, "Plateau ", 8) == 0)
	{
		tmp = ft_strsplit(input->line, ' ');
		input->by = ft_atoi(tmp[1]);
		input->bx = ft_atoi(tmp[2]);
		ft_strdel(tmp);
	}
	if (ft_strncmp(input->line, "Piece ", 6) == 0)
	{
		tmp = ft_strsplit(input->line, ' ');
		input->py = ft_atoi(tmp[1]);
		input->px = ft_atoi(tmp[2]);
		ft_strdel(tmp);
	}
	if (ft_isdigit(*input->line))
	{
		if (!input->board && !(input->board = (char **)malloc(sizeof(char *) * input->by)))
			return ;
		input->board[input->by] = NULL;
		input->board[input->i] = ft_strdup(ft_strchr(input->line, '.'));
		input->i += 1;
	}
	if (*input->line == '.' || *input->line == '*')
	{
		if (!input->piece) 
			if (!(input->piece = (char **)malloc(sizeof(char *) * input->py + 1)))
				return ;
		input->piece[input->py] = NULL;
		input->piece[input->j] = ft_strdup(input->line);
		input->j++;
		if (input->j == input->py)
		{
			input->isdone = 1;
			//input->piece = NULL;
		}
	}
}
