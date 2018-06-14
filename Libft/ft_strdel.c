#include "libft.h"

void	ft_strdel(char **as)
{
	if (!as)
		return ;
	while (*as)
	{
		*as = 0;
		free(*as);
	}
}
