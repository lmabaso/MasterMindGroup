/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 08:21:20 by lmabaso           #+#    #+#             */
/*   Updated: 2018/06/22 08:24:40 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	tocopy;
	char			*tmp;

	tocopy = (unsigned char)c;
	tmp = (char *)s;
	while (n > 0)
	{
		*tmp = tocopy;
		tmp++;
		n--;
	}
	return (s);
}
