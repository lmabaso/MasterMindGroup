#include "filler.h"

t_list	*insertion_sort(t_list *head)
{
	t_list *x;
	t_list *y;
	t_list *z;
	t_best *a;
	t_best *b;
	t_best *c;

	x = head;
	head = NULL;
	while (x != NULL)
	{
		z = x;
		x = x->next;
		if (head != NULL)
		{
			a = z->content;
			b = head->content;
			if (a->score > b->score)
			{
				y = head;
				c = y->next->content;
				while ((y->next != NULL) && (a->score > c->score))
				{
					y = y->next;
				}
				z->next = y->next;
				y->next = z;
			}
			else
			{
				z->next = head;
				head = z;
			}
		}
		else
		{
			z->next = NULL;
			head = z;
		}
	}
	return (head);
}