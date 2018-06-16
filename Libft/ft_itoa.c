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

char	*ft_itoa(int n)
{
	char *num;
	int end;
	int sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	end = ft_leni(n);
	sign = 0;
	if (n < 0)
	{
		n*=-1;
		sign = 1;
		end++;
	}
	if (!(num = ft_strnew(end)))
		return (NULL);
	while (end--)
	{
		num[end] = (n % 10) + 48;
		n = n / 10;
	}
	num[0] = (sign == 1) ? '-' : num[0];
	return (num);
}
