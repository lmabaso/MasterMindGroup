#include "libft.h"

int		ft_leni(int n)
{
	int i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

#include <stdio.h>

char	*ft_itoa(int n)
{
	char *num;
	size_t end;
	int i;

	end = ft_leni(n);
	i = 0;
	if (n < 0)
	{
		n*=-1;
		i = 1;
		end++;
		}
	if (!(num = ft_strnew(end + 1)))
		return (NULL);
	while (end--)
	{
		num[end] = (n % 10) + 48;
		n = n / 10;
	}
	num[0] = (i == 1) ? '-' : num[0];
	return (num);
}
