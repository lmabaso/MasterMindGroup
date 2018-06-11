#include "libft.h"

char *ft_strncat(char *dest, const char *src, size_t n)
{
	size_t index;
	size_t len;

	index = 0;
	len = 0;
	while (dest[len])
		len++;
	while (n)
	{
		dest[len + index] = src[index];
		index++;
		n--;
	}
	dest[len + index] = '\0';
	return (dest);
}