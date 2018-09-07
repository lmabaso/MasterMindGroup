#include "libft.h"

size_t	ft_strulen(const unsigned char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}