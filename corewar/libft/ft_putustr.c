#include "libft.h"

void	ft_putustr_fd(int size, unsigned char *str, int fd)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putuchar_fd(str[i], fd);
		i++;
	}
}