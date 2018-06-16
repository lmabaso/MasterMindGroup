#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	dlen;
	int		flag;

	dlen = ft_strlen(dest) + n;
	dest = dest + (dlen - n);
	flag = (n > ft_strlen(src)) ? 1 : 0;
	while (*src && n--)
		*dest++ = *src++;
	if (!flag)
		*dest = '\0';
	else
		while (n--)
			*dest++ = '\0';
	return (dest - dlen);
}
