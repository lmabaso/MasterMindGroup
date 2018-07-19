#include "filler.h"

void		deleteList(t_list **head_ref)
{
   t_list	*current = *head_ref;
   t_list	*next;
 
   while (current != NULL)
   {
       next = current->next;
	   free(current->content);
       free(current);
       current = next;
   }
   *head_ref = NULL;
}

void        ft_free_boards(t_obj *input)
{
    input->i = 0;
    while (input->i < input->by)
    {
        input->j = 0;
        while (input->j < input->bx)
        {
			deleteList(&input->aboard[input->i][input->j].neighbours);
            input->j++;
        }
        free(input->aboard[input->i]);
        input->i++;
    }
	free(input->aboard);
}

void	ft_freeall(t_obj *input)
{
	int i;

	i = 0;
	while (i < input->by)
	{
		free(input->board[i]);
		i++;
	}
    free(input->board);
}

void    ft_free_2dchr(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
    str = NULL;
}



void	ft_makezero(t_obj *input)
{
	input->isdone = 0;
    // ft_put_to_co(&input->bestmove, 0, 0);
	// ft_freeall(input);
	// ft_free_2dchr(input->piece);
	deleteList(&input->realpiece);
	// ft_free_boards(input);
	deleteList(&input->moves);
	// if (input->realpiece)
		// ft_lstfree(input->realpiece);
	// free(input->aboard);
	input->i = 0;
	input->j = 0;
}