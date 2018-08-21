#include "../includes/push_swap.h"

void        ft_rotate_up(t_list **head)
{
    t_list		*current;
	t_list		*hold;

	hold = *head;
	if (hold && hold->next)
	{
		*head = (*head)->next;
		hold->next = NULL;
		current = *head;
		while (current->next)
			current = current->next;
		current->next = hold;
	}
}

void        ft_rotate_dwn(t_list **head)
{
    t_list		*current;
	t_list		*hold;

	hold = *head;
	if (*head && (*head)->next)
	{
		while (hold->next)
		{
			current = hold;
			hold = hold->next;
		}
		current->next = NULL;
		hold->next = *head;
		*head = hold;
	}
}

void        ft_rotate_up_rr(t_list **head_a, t_list **head_b)
{
	ft_rotate_up(head_a);
	ft_rotate_up(head_b);
}

void		ft_rotate_dwn_rr(t_list **head_a, t_list **head_b)
{
	ft_rotate_dwn(head_a);
	ft_rotate_dwn(head_b);
}