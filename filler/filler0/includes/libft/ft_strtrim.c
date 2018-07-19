/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 09:29:59 by lmabaso           #+#    #+#             */
/*   Updated: 2018/06/29 12:28:53 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t end;
	size_t start;

	if (!s)
		return (NULL);
	end = ft_strlen(s) - 1;
	start = 0;
	while (ft_isspace(s[start]))
		start++;
	while (ft_isspace(s[end]))
		end--;
	return (!s[start] ? ft_strdup("") : ft_strsub(s, start, end - start + 1));
}
