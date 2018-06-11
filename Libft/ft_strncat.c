#include "libft.h"

char *ft_strncat(char *dest, const char *src, size_t n)
{
	size_t dlen;

	dlen = ft_strlen(dest) + n;
	while (*dest)
		dest++;
	while (*src && n--)
		*dest++ = *src++;
	*dest = '\0';
	return (dest - dlen);
}
