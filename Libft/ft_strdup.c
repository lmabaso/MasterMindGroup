#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *ptr;
	int i;

	if (!(ptr = (char *)malloc(ft_strlen((char *)s) + 1)))
			return (NULL);
	i = 0;
	while (*s)
	{
		*ptr++ = *s++;
		i++;
	}
	*ptr = '\0';
	return (ptr - i);
}
