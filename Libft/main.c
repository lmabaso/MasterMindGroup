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

	printf("Memccpy\t");
	if (memcmp(memccpy(str, var, 't', 7), ft_memccpy(tstr, var,'t', 7), 7) == 0)
		printf("[Pass]\n");
	else
		printf("[Fail]\n");
	// printf("%s\n", (char *)memccpy(str, var, 't', 7));
	// printf("%s\n", (char *)ft_memccpy(tstr, var, 't', 7));
}

void	testStrncat(void)
{
	char str[] = "This is dest string";
	char tstr[] = "This is dest string";
	char var[] = "liberty for src string";

	printf("strncat\t");
	if (strcmp(strncat(str, var, 7), ft_strncat(tstr, var, 7)) == 0)
		printf("[Pass]\n");
	else
		printf("[Fail]\n");
	// printf("Ours %s\n", tstr);
	// printf("System %s\n", str);

}

void	testStrlcat(void)
{
	char str[] = "This is dest string";
	char tstr[] = "This is dest string";
	char var[] = "liberty for src string";

	printf("strlcat\t");
	if (strlcat(str, var, 7) == ft_strlcat(tstr, var, 7))
		printf("[Pass]\n");
	else
		printf("[Fail]\n");
	printf("Ours %s \n",str/*, strlcat(str, var, 7)*/);
	printf("System %s \n",tstr/*, ft_strlcat(tstr, var, 7)*/);

}

int		main(void)
{
	
	testMemset();
	testBzero();
	testMemcpy();
	testMemccpy();
	testStrncat();
	testStrlcat();
	return(0);
}
