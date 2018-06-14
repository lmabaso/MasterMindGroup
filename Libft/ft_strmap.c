#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *tmp;
	int len;

	if (!s || !(tmp = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	len = 0;
	while (*s)
	{
		tmp[len] = (*f)(*s++);
		len++;
	}
	tmp[len] = '\0';
	return (tmp);
}
