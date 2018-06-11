#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*s == c)
			return ((char *)s);
		else if (!*s)
			break ;
		s++;
	}
	return (NULL);
}
