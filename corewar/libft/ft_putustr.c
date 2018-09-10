#include "libft.h"

void	ft_putustr_fd(unsigned char *str, int fd)
{
	while (*str)
	{
		ft_putuchar_fd(*str, fd);
		str++;
	}
}