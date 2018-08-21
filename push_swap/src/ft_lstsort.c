#include "../includes/push_swap.h"

void FrontBackSplit(t_list *source, t_list **frontRef, t_list **backRef)
{
	t_list *fast;
	t_list *slow;

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
	*frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

t_list *SortedMerge(t_list *a, t_list *b)
{
	t_list *result = NULL;
	int *i;
	int *j;
	
	if (a == NULL)
		return(b);
	else if (b==NULL)
		return(a);
	i = a->content;
	j = b->content;
	if (i <= j)
	{
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return(result);
}

void MergeSort(t_list **headRef)
{
	t_list *head = *headRef;
	t_list *a;
	t_list *b;

	if ((head == NULL) || (head->next == NULL))
		return ;
	FrontBackSplit(head, &a, &b);
	MergeSort(&a);
	MergeSort(&b);
	*headRef = SortedMerge(a, b);
}