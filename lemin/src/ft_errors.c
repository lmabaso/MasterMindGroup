/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:12:46 by lmabaso           #+#    #+#             */
/*   Updated: 2018/08/30 16:47:19 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int				ft_same_co(t_node *room)
{
	t_node		*tmp;
	t_node		*tmp1;

	tmp = room;
	while (tmp && tmp->next)
	{
		tmp1 = tmp;
		while (tmp1->next)
		{
			if (tmp->data.pos.x == tmp1->next->data.pos.x)
				if (tmp->data.pos.y == tmp1->next->data.pos.y)
					return (1);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int				ft_is_only_space(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int				ft_dup(t_string *input)
{
	t_string	*tmp;
	t_string	*tmp1;

	tmp = input;
	while (tmp && tmp->next)
	{
		tmp1 = tmp;
		while (tmp1->next)
		{
			if (ft_strequ(tmp->str, tmp1->next->str))
				return (1);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int				ft_err_room(t_string *tmp)
{
	char		**s;

	s = ft_strsplit(tmp->str, ' ');
	if (ft_double_ptr_len((void **)s) == 3)
	{
		if (s[0][1] == 'L')
			return (1);
		if (!ft_isnumber(s[1]) || !ft_isnumber(s[2]))
			return (1);
	}
	if (ft_strncmp(tmp->str, "###", 3) == 0)
		return (1);
	if (ft_strequ(tmp->str, "##start") || ft_strequ(tmp->str, "##end"))
	{
		if (tmp->next->str[0] == '#')
			return (1);
		s = ft_strsplit(tmp->next->str, ' ');
		if (ft_double_ptr_len((void **)s) == 3 &&
				(!ft_isnumber(s[1]) || !ft_isnumber(s[2])))
			return (1);
		else if (ft_strchr(tmp->next->str, '-') &&
				ft_double_ptr_len((void **)s) == 2)
			return (1);
	}
	return (2);
}

int				ft_error_handle(t_string **input)
{
	t_string	*tmp;
	int			pipes;

	pipes = 0;
	tmp = *input;
	if (!ft_isnumber(tmp->str) || ft_dup(*input) ||
			!ft_search(*input, "##start") || !ft_search(*input, "##end"))
		return (1);
	if (ft_isnumber(tmp->str))
	{
		if (ft_atoi(tmp->str) <= 0)
			return (1);
		tmp = tmp->next;
		if (ft_strequ(tmp->str, "##start"))
		{
			tmp = tmp->next;
			if (tmp->next->str[0] == '#')
				return (1);
		} 
		else if (tmp->str[0] == '#')
			return (1);
	}
	while (tmp)
	{
		if (ft_err_room(tmp) == 1)
			return (1);
		if (ft_strchr(tmp->str, '-'))
		{
			pipes++;
			break ;
		} 
		tmp = tmp->next;
	}
	if (!pipes)
		return (1); 
	while (tmp)
	{
		if (ft_err_pipes(tmp, input) == 1)
			return (1);
		if (ft_is_only_space(tmp->str))
		{
			if (ft_is_not_eof(tmp) == 1)
				return (1);
			break ;
		}
		tmp = tmp->next;
	}
	return (0);
}
