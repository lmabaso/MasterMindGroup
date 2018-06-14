#include "libft.h"

void	ft_memdel(void **ap)
{
	if (!ap)
		return ;
	while (*ap)
	{
		*ap = 0;
		free(*ap);
	}
}
