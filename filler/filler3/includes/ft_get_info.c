#include "filler.h"

void	ft_findplayer(t_obj *input)
{
	char **tmp;
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
		if (!input->piece && !(input->piece = (char **)malloc(sizeof(char *) * input->py + 1)))
			return ;
		while (input->j < input->py)
		{
			get_next_line(0, &input->line);
			input->piece[input->j] = ft_strdup(input->line);
			input->j++;
		}
		input->piece[input->j] = NULL;
		if (input->j == input->py)
			input->isdone = 1;
	}
}

void	ft_get_info(t_obj *input)
{
	ft_findplayer(input);
	if (ft_strncmp(input->line, "$$$ exec ", 9) == 0)
	{
		input->player = ft_strsub(input->line, 9, 2);
		input->mypiece = (ft_strcmp(input->player, "p1") == 0) ? 'O' : 'X';
		input->oppiece = (input->mypiece == 'O') ? 'X' : 'O';
	}
	if (*input->line == ' ')
	{
		if (!input->board && !(input->board = (char **)malloc(sizeof(char *) * input->by)))
			return ;
		while (input->i < input->by)
		{
			get_next_line(0, &input->line);
			while (ft_isdigit(*input->line) || ft_isspace(*input->line))
				input->line += 1;
			input->board[input->i] = ft_strdup(input->line);
			input->i += 1;
		}
		input->board[input->i] = NULL;
	}
}
