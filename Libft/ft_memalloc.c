#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;

	if(!(ptr = malloc(size)))
		return (NULL);
	return (ft_memset(ptr, 0, size));
}
