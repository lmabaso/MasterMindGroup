#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char toCopy;
	size_t index;
	char *tmp;

	toCopy = (unsigned char)c;
	index = 0;
	tmp = (char *)s;
	while (index < n)
	{
		*tmp = toCopy;
		tmp++;
		index++;
	}
	return (s);
}
