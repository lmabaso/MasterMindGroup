#include "filler.h"

double	ft_sqrt(double num)
{
	int i;
	int result;

	i = 1;
	result = 1;
	if (num == 0 || num == 1)
		return (num);
	while (result <= num)
	{
		i++;
		result = i * i;
	}
	return (i - 1);
}

double getDistance(t_co a, t_co b)
{
	double distance;

	distance = ft_sqrt((a.x - b.x) * (a.x - b.x) + (a.y-b.y) * (a.y-b.y));
	return (distance);
}