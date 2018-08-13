/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:04:49 by lmabaso           #+#    #+#             */
/*   Updated: 2018/06/29 12:13:58 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_leni(int n)
{
	int i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char		*num;
	int			end;
	int			sign;
	long int	nu;

	nu = (long int)n;
	if (nu == 0)
		return (ft_strdup("0"));
	end = ft_leni(nu);
	sign = 0;
	if (nu < 0)
	{
		nu *= -1;
		sign = 1;
		end++;
	}
	if (!(num = ft_strnew(end)))
		return (NULL);
	while (end--)
	{
		num[end] = (nu % 10) + 48;
		nu = nu / 10;
	}
	num[0] = (sign == 1) ? '-' : num[0];
	return (num);
}
