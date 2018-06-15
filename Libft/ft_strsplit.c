#include "libft.h"

int		ft_len(char const *s, char c)
{
	int count;

	count = 0;
	while (s[count])
	{
		if (s[count] == c)
			return (count);
		count++;
	}
	return (count);
}

int		ft_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			count++;
		s++;
	}
	if (!(*s))
		count++;
	return (count);
}

#include <stdio.h>

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		elements;
	int		len;
	char	**ptr;

	elements = ft_count(s, c);
	len = 0;
	str = NULL;
	if ((str = (char **)malloc(sizeof(char *) * (elements + 1))))
	{
		ptr = str;
		while (elements--)
		{
			len = ft_len(s, c) + 1;
			*str = ft_strsub(s, 0, len - 1);
			s = s + len;
			str++;
		}
		str = '\0';
	}
	return (ptr);
}
