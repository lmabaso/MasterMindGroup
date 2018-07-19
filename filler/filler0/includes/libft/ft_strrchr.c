/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 08:45:34 by lmabaso           #+#    #+#             */
/*   Updated: 2018/06/22 08:46:52 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t s_len;

	s_len = ft_strlen(s);
	while (1)
	{
		if (s[s_len] == c)
			return ((char *)&s[s_len]);
		else if (!s_len)
			break ;
		s_len--;
	}
	return (NULL);
}
