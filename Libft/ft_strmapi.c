#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *tmp;
	unsigned int len;

	if (!s || !(tmp = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	len = 0;
	while (*s)
	{
		tmp[len] = (*f)(len, *s++);
		len++;
	}
	tmp[len] = '\0';
	return (tmp);
}
