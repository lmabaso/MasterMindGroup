#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *d;
	unsigned char *s;
	unsigned char toStop;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	toStop = (unsigned char)c;
	while (n > 0 && *s != toStop)
	{
		*d++ = *s++;
		n--;
	}
	return (dst);
}
