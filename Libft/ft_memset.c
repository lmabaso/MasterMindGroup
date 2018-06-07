#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char toCopy;
	char *tmp;

	toCopy = (unsigned char)c;
	tmp = (char *)s;
	while (n > 0)
	{
		*tmp = toCopy;
		tmp++;
		n--;
	}
	return (s);
}
