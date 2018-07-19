/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 08:49:05 by lmabaso           #+#    #+#             */
/*   Updated: 2018/06/22 08:51:23 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t n_len;

	if (!ft_strcmp(needle, ""))
		return ((char *)haystack);
	n_len = ft_strlen(needle);
	while (*haystack)
	{
		if (*haystack == *needle)
			if (ft_strncmp(haystack, needle, n_len) == 0)
				return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
