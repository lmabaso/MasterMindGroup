#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (*src)
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	return (dst - i);
}
