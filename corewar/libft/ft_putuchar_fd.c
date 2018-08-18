#include "libft.h"

void	ft_putuchar_fd(unsigned char c, int fd)
{
	write(fd, &c, 1);
}