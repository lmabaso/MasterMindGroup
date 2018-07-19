#include "filler.h"

void	ft_board_x(int i, t_spot ***temp, t_obj input)
{
	t_spot	**board;
	int		j;

	board = *temp;
	j = 0;
	while (j < input.bx)
	{
		board[i][j].neighbours = ft_get_neighbours(i, j, input);
		board[i][j].x = i;
		board[i][j].y = j;
		board[i][j].state = input.board[i][j];
		if (board[i][j].state == '.')
			board[i][j].score = 0;
		if (board[i][j].state == input.mypiece || board[i][j].state == ft_tolower(input.mypiece))
			board[i][j].score = -2;
		if (board[i][j].state == input.oppiece || board[i][j].state == ft_tolower(input.oppiece))
			board[i][j].score = -1;
		j++;
	}
	*temp = board;
}

void	ft_get_score(t_obj input, t_spot ***temp)
{
	int		i;
	int		j;
	t_co	tmp1;
	t_co	tmp;
	t_spot	**board;

	board = *temp;
	i = 0;
	while (i < input.by)
	{
		j = 0;
		while (j < input.bx)
		{
			if (board[i][j].score == 0)
			{
				tmp1.x = j;
				tmp1.y = i;
				tmp = ft_find_close(i, j, input);
				board[i][j].score = (int)ft_get_distance(tmp, tmp1);
			}
			j++;
		}
		i++;
	}
	*temp = board;
}

t_spot	**ft_makeboard(t_obj input)
{
	t_spot	**board;
	int		i;

	i = 0;
	if (!(board = (t_spot **)malloc(sizeof(t_spot *) * input.by)))
		return (NULL);
	while (i < input.by)
	{
		if (!(board[i] = (t_spot *)malloc(sizeof(t_spot) * input.bx)))
			return (NULL);
		ft_board_x(i, &board, input);
		i++;
	}
	ft_get_score(input, &board);
	return (board);
}
