#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ptr;

	if(!(ptr = (char *)malloc(size + 1)))
		return (NULL);
	return ((char *)ft_memset(ptr, 0, size + 1));
}
