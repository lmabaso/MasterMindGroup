/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:48:10 by lmabaso           #+#    #+#             */
/*   Updated: 2018/06/28 13:16:12 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!ft_strcmp(needle, ""))
		return ((char *)haystack);
	while (*haystack)
	{
		if (len < ft_strlen(needle))
			break ;
		if (*haystack == *needle)
			if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
				return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
