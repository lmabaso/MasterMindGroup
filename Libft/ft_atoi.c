#include "libft.h"

int	ft_atoi(const char *str)
{
	int sign;
	long long num;

	sign = 1;
	num = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' && str++)
		if (*str == '-')
			return (0);
	if (*str == '-' && str++)
		sign = -1;
	while (ft_isdigit(*str))
		num = num * 10 + (*str++ - '0');
	return ((int)num * sign);
}
