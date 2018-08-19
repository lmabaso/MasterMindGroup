#include "../includes/corewar.h"

void	ft_lfree(t_node **head)
{
	t_node  *current;
    t_node  *next;

    current = *head;
    while (current != NULL)
    {
		if (current->entry.label)
			free(current->entry.label);
		free(current->entry.opcode);
		free(current->entry.data);
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

void	ft_to_free(t_obj *c)
{
	ft_lfree(&c->raw);
	free(c->info);
}