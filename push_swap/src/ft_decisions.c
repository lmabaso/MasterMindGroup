#include "../includes/push_swap.h"

char        *ft_sort3(t_list **head)
{
	if (ft_issorted(head))
		return ("ok");
	if (ft_isrsorted(head) || ft_first(head) == ft_max(head))
		return ("ra");
	if (ft_second(head) == ft_min(head))
		return ("sa");
	return ("rra");
}

char        *ft_sort10(t_list **a, t_list **b)
{
	int i;

	i = ft_lstlen(*a);
	if (ft_issorted(a) && ! *b)
		return ("ok");
	if (*b && ft_issorted(a) && ft_isrsorted(b))
		return ("pa");
	if (i == 3)
		return ((ft_strncmp(ft_sort3(a), "ok", 2) == 0) ?  "pa" : ft_sort3(a));
	if (ft_min(a) == ft_first(a))
		return ("pb");
	return ((ft_pos(a, ft_min(a)) <= i / 2) ? "ra" : "rra");
}

char        *ft_make(t_list **a, t_list **b, size_t i)
{
	if (i == 2)
		return (ft_issorted(a) ? "ok" : "sa");
	if (i == 3)
		return (ft_sort3(a));
	if (i <= 10)
		return (ft_sort10(a, b));
	return (ft_sort(a, b));
}