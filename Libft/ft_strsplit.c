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
	int inSub;

	inSub = 0;
	count = 0;
	while (*s)
	{
		inSub = (inSub && *s == c) ? 0 : inSub;
		if (!inSub && *s !=c)
		{
			count++;
			inSub = 1;
		}
		s++;
	}
	return (count);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		elements;
	char	**ptr;

	if (!s)
		return (NULL);
	elements = ft_count(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * (elements))))
		return (NULL);
	ptr = str;
	while (elements--)
	{
		while (*s == c && *s)
			s++;
		*str++ = ft_strsub(s, 0, ft_len(s, c));
		if (!str)
			return (NULL);
		s = s + ft_len(s, c);
	}
	*str = NULL;
	return (ptr);
}
