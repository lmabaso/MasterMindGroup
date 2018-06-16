#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	tocopy;
	char			*tmp;

	tocopy = (unsigned char)c;
	tmp = (char *)s;
	while (n > 0)
	{
		*tmp = tocopy;
		tmp++;
		n--;
	}
	return (s);
}
