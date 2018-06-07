#include "libft.h"
#include <stdio.h>


void testMemset(void)
{
	char str[50];
	char tstr[50];
	char var[] = "liberty";

	strcpy(str, var);
	strcpy(tstr, var);

	ft_memset(str, '#', 4);
	memset(tstr, '#', 4);

	if (memcmp(str, tstr, 7) == 0)
		printf("Pass\n");
	else
		printf("Failed\n");

}

int		main(void)
{
	testMemset();
	return(0);
}
