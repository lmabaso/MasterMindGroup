#include "libft.h"
#include "ctype.h"

int	ft_atoi(const char *str)
{
	int sign;
	long num;

	sign = 1;
	num = 0;
	while (ft_isspace(*str) || *str == '+')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (isdigit(*str))
		num = num * 10 + (*str++ - '0');
	return ((int)num * sign);
}
