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
	printf("Memset\t");
	if (memcmp(str, tstr, 7) == 0)
		printf("[Pass]\n");
	else
		printf("[Failed]\n");

}

void testBzero(void)
{
	char str[50];
	char tstr[50];
	char var[] = "liberty";

	strcpy(str, var);
	strcpy(tstr, var);

	ft_bzero(str, 4);
	bzero(tstr, 4);
	printf("Bzero\t");
	if (memcmp(str, tstr, 7) == 0)
		printf("[Pass]\n");
	else
		printf("[Failed]\n");
}

void testMemcpy(void)
{
	char str[50];
	char tstr[50];
	char var[] = "liberty";

	memcpy(str, var, 7);
	ft_memcpy(tstr, var, 7);

	printf("Memcpy\t");
	if (memcmp(str, tstr, 7) == 0)
		printf("[Pass]\n");
	else
		printf("[Failed]\n");
}

void testMemccpy(void)
{
	char str[50];
	char tstr[50];
	char var[] = "liberty";

	memccpy(str, var, 't', 7);
	ft_memccpy(tstr, var,'t', 7);

	printf("Memccpy\t");
	if (memcmp(str, tstr, 7) == 0)
		printf("[Pass]\n");
	else
		printf("[Failed]\n");
}

int		main(void)
{
	
	testMemset();
	testBzero();
	testMemcpy();
	testMemccpy();
	return(0);
}
