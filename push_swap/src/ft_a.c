#include "../includes/push_swap.h"

void				expandNode(t_asnode *node)
{
	ft_rra(node);
	ft_ra(node);
	ft_sa(node);
}

t_list *copy(t_list *L1)
{
     t_list *L2 = 0;
     t_list *preElem = 0;

     while(L1 != 0) {
          t_list *elem = ft_memalloc(sizeof(t_list));
          if(elem == 0) {
               exit(1);
          }
          elem->content = L1->content;
          elem->next = 0;
          if (L2 == 0) {
                L2 = elem;
                preElem = elem;
          }
          else {
                preElem->next = elem;
                preElem = elem;
		  }
          L1 = L1->next;
    }
    return L2;
}

char				*ft_sa(t_asnode *node)
{
	t_list			*pc;
	t_asnode		*child;
	
	pc = NULL;
	child = ft_memalloc(sizeof(t_asnode));
	pc =  copy(node->puzzle);
	ft_update(&pc, NULL, "sa");
	child->puzzle = pc;
	child->goal = node->goal;
	ft_lstadd(&node->neighbours, ft_lstnew(child, sizeof(t_asnode)));
	return ("sa");
}



char				*ft_ra(t_asnode *node)
{
	t_list			*pc;
	t_asnode		*child;
	
	pc = NULL;
	child = ft_memalloc(sizeof(t_asnode));
	
	pc =  copy(node->puzzle);
	ft_update(&pc, NULL, "ra");
	child->puzzle = pc;
	child->goal = node->goal;
	ft_lstadd(&node->neighbours, ft_lstnew(child, sizeof(t_asnode)));
	return ("ra");
}

char				*ft_rra(t_asnode *node)
{
	t_list			*pc;
	t_asnode		*child;
	
	pc = NULL;
	child = ft_memalloc(sizeof(t_asnode));
	pc =  copy(node->puzzle);
	ft_update(&pc, NULL, "rra");
	child->puzzle = pc;
	child->goal = node->goal;
	ft_lstadd(&node->neighbours, ft_lstnew(child, sizeof(t_asnode)));
	return ("rra");
}

int					ft_is_same_puzzle(t_list *p1, t_list *p2)
{
	int *i1;
	int *i2;
	if (p1 && !p2)
		return (0);
	if (!p1 && p2)
		return (0);
	while (p1 && p2)
	{
		i1 = p1->content;
		i2 = p2->content;
		if (i1 != i2)
			return (0);
		p1 = p1->next;
		p2 = p2->next;
	}
	return ((!p1 && !p2) ? 1 : 0);
}

void 		deleteNode(t_list **head_ref, int position)
{
	t_list* temp = *head_ref;
	
	if (*head_ref == NULL)
		return ;
    if (position == 0)
    {
        *head_ref = temp->next;   // Change head
        free(temp);               // free old head
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++)
         temp = temp->next;
    if (temp == NULL || temp->next == NULL)
         return;

    t_list *next = temp->next->next;
    free(temp->next);  // Free memory
    temp->next = next;  // Unlink the deleted node from list
}

int			ft_isinlist(t_list *head, t_asnode *find)
{
	t_asnode *tmp;
	t_list	*tp;

	if (!head)
		return (0);
		(void)find;
	while (head)
	{
		tmp = head->content;
		tp = tmp->puzzle;
		ft_putnbr(*(int *)tp->content);
		ft_putchar(' ');
		head = head->next;
	}
	// while (head)
	// {
	// 	tmp = head->content;
	// 	if (ft_is_same_puzzle(tmp->puzzle, find->puzzle))
	// 		return (1);
	// 	head = head->next;
	// }
	
	return (0);
}

double			ft_manhatton(t_asnode *node)
{
	double h;

	h = 0.0;

	while (node->puzzle)
	{
		if (*(int *)node->puzzle->content != *(int *)node->goal->content)
			h++;
		node->goal = node->goal->next;
		node->puzzle = node->puzzle->next;
	}
	return (h);
}


t_list			*AStar(t_asnode *node)
{
	t_list 		*PathToSolution = NULL;
	t_list		*openSet = NULL;
	t_list		*closedSet = NULL;
	t_asnode	*current = NULL;
	t_asnode	*tmp = NULL;
	t_asnode	*neighbour = NULL;
	t_list 		*t1 = NULL;
	t_list		*t2 = NULL;
	double		tmpG = 0.0;

	ft_lstadd(&openSet, ft_lstnew(node, sizeof(t_asnode)));
	
	while (ft_lstlen(openSet) > 0)
	{
		
		int	pos;
		int count;
		t1 = openSet;
		t2 = openSet->next;
		t_asnode *cm1;
		t_asnode *cm2;
		count = 0;
		pos = 0;
		current = openSet->content;
		while (t1 && t2)
		{
			
			cm1 = t1->content;
			cm2 = t2->content;
			if (cm2 && cm1->f < cm2->f)
			{
				current = cm1;
				pos = count;
			}	
			t1 = t1->next;
			t2 = t2->next;
			count++;
		}
		if (ft_is_same_puzzle(cm1->puzzle, cm1->goal))
		{
			tmp = current;
			ft_lstadd(&PathToSolution, ft_lstnew(tmp, sizeof(t_asnode)));
			while (tmp->previuos != NULL)
			{
				ft_lstadd(&PathToSolution, ft_lstnew(tmp->previuos, sizeof(t_asnode)));
				tmp = tmp->previuos;
			}
			break ;
		}
		ft_lstadd(&closedSet, ft_lstnew(current, sizeof(t_asnode)));
		
		deleteNode(&openSet, pos);
		current = ft_memalloc(sizeof(t_asnode));
		expandNode(current);
		
		t_asnode *tmpasn;
		while (current->neighbours)
		{
			tmpasn = current->neighbours->content;
			//if (tmpasn->previuos != NULL)
			//{
				
				// if (!ft_is_same_puzzle(tmpasn->puzzle, tmpasn->previuos->previuos->puzzle))
				// {
				// 	
				// 	neighbour = tmpasn;
				// 	if (!ft_isinlist(closedSet, neighbour))
				// 	{
				// 		tmpG = current->g + 1;
				// 		if (ft_isinlist(openSet, neighbour))
				// 		{
				// 			if (tmpG < neighbour->g)
				// 				neighbour->g = tmpG;
				// 		}
				// 		else
				// 		{
				// 			neighbour->g = tmpG;
				// 			ft_lstadd(&openSet, ft_lstnew(neighbour, sizeof(t_asnode)));
				// 		}
				// 		neighbour->h = ft_manhatton(neighbour);
				// 		neighbour->f = neighbour->g + neighbour->h;
				// 		neighbour->previuos = current;
				// 		neighbour->next = NULL;
				// 	}
				// }
				// else
				// {
					
					neighbour = tmpasn;
					if (!ft_isinlist(closedSet, neighbour))
					{
						ft_putendl("linser");
						tmpG = current->g + 1;
						if (ft_isinlist(openSet, neighbour))
						{
							if (tmpG < neighbour->g)
								neighbour->g = tmpG;
						}
						else
						{
							neighbour->g = tmpG;
							ft_lstadd(&openSet, ft_lstnew(neighbour, sizeof(t_asnode)));
						}
						neighbour->h = ft_manhatton(neighbour);
						neighbour->f = neighbour->g + neighbour->h;
						neighbour->previuos = current;
						neighbour->next = NULL;
					}
				// }
			//}
			
			current->neighbours = current->neighbours->next;
		}
	}
	return (PathToSolution);
}

void		ft_fb_split(t_list *source, t_list **front, t_list **back)
{
	t_list	*fast;
	t_list	*slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front = source;
	*back = slow->next;
	slow->next = NULL;
}

t_list		*ft_sorted_merge(t_list *a, t_list *b)
{
	t_list	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (*(int *)a->content <= *(int *)b->content)
	{
		result = a;
		result->next = ft_sorted_merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = ft_sorted_merge(a, b->next);
	}
	return (result);
}

void		ft_mergesort(t_list **head)
{
	t_list	*current;
	t_list	*a;
	t_list	*b;

	current = *head;
	if ((current == NULL) || (current->next == NULL))
		return ;
	ft_fb_split(current, &a, &b);
	ft_mergesort(&a);
	ft_mergesort(&b);
	*head = ft_sorted_merge(a, b);
}


void		bozzathing(t_list **a)
{
	t_asnode *node;
	t_list	*pc;
	t_list	*res;

	node = ft_memalloc(sizeof(t_asnode));
	node->previuos = NULL;
	node->puzzle = *a;
	pc = copy(*a);

	ft_mergesort(&pc);
	node->goal = pc;
	
	res = AStar(node);
	
	while (res)
	{
		ft_putendl((char *)pc->content);
		ft_putchar(' ');
		res = res->next;
	}
}