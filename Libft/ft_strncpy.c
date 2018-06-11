#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;
	size_t srclen;

	i = 0;
	srclen = ft_strlen((char *)src);
	while (i < len)
	{
		if (i <= srclen)
			dst[i] = src[i];
		else
			dst[i] = '\0';
		i++;
	}
	return (dst);
}
