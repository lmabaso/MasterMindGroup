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

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		elements;
	int		len;
	char	**ptr;

	if (!s)
		return (NULL);
	elements = ft_count(s, c) + 1;
	len = 0;
	if (!(str = (char **)malloc(sizeof(char *) * (elements))))
		return (NULL);
	ptr = str;
	while (elements--)
	{
		len = ft_len(s, c) + 1;
		*str = ft_strsub(s, 0, len - 1);
		s = s + len;
		str++;
		if (!str)
			return (NULL);
	}
	*str = (void *)0;
	return (ptr);
}
