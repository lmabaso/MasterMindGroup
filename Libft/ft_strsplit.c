#include "libft.h"

int		ft_len(char const *s, char c)
{
	int count;

	count = 0;
	while (s[count])
	{
		if (s[count] == c && s[count]!= '\0')
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
		if (!inSub && *s != c)
		{
			inSub = 1;
			count++;
		}
		s++;
	}
	return (count);
}

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
			while (*s == c)
				s++;
			len = ft_len(s, c) + 1;
			*str = ft_strsub(s, 0, len - 1);
			s = s + len;
			str++;
		}
		str = '\0';
	}
	return (ptr);
}
