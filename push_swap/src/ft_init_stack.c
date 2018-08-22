/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 14:36:58 by lmabaso           #+#    #+#             */
/*   Updated: 2018/08/21 14:39:38 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		init_check(int ac, char **av, t_list **a, t_list **b)
{
	int		f;

	av += 1;
	ac -= 1;
	f = ((ac == 1 && ft_strcontains(av[0], ' ')) ? 1 : 0);
	ft_correct(&ac, &av);
	ft_check_for_errors(ac, av);
	*a = ft_fresh_stack(ac, av);
	*b = NULL;
	if (f)
		ft_free_2d((void **)av);
}

t_list		*ft_fresh_stack(int ac, char **av)
{
	int		i;
	int		tmp;
	t_list	*stack;

	stack = NULL;
	i = 0;
	ac--;
	while (i <= ac)
	{
		if (ft_is_in_stack(stack, ft_atoi(av[ac - i])))
		{
			ft_lstfree(&stack);
			ft_putendl("Error");
			exit(1);
		}
		tmp = ft_atoi(av[ac - i]);
		ft_lstadd(&stack, ft_lstnew(&tmp, sizeof(int)));
		i++;
	}
	return (stack);
}
