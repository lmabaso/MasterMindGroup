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
	char *s1;
	char *s2;

	printf("Memccpy\t");
<<<<<<< HEAD
	s1 = memccpy(str, var, '#', 7);
	s2 = ft_memccpy(tstr, var,'#', 7);
	if (s1 == NULL && s2 == NULL)
		printf("Pass");
	else if (memcmp(s1, s2, strlen(s1)) == 0)
	 	printf("[Pass]\n");
	else
	 	printf("[Fail]\n");
	
	printf("\n");
	printf("%s\n", s1);
	printf("%s\n", s2);
}

void	testStrcat()
{
	char s1[50] = "BMW";
	char s2[] = "Volvo";	
	char s3[50] = "BMW";
	char s4[] = "Volvo";
	printf("strcat: %s\n", strcat(s1, s2));
	printf("ft_strcat: %s\n", ft_strcat(s3, s4));
=======
	if (memcmp(memccpy(str, var, 't', 7), ft_memccpy(tstr, var,'t', 7), 7) == 0)
		printf("[Pass]\n");
	else
		printf("[Fail]\n");
	printf("%s\n", (char *)memccpy(str, var, 't', 7));
	printf("%s\n", (char *)ft_memccpy(tstr, var, 't', 7));
>>>>>>> parent of 7bd5506... lmabaso
}

int		main(void)
{
	
	testMemset();
	testBzero();
	testMemcpy();
	testMemccpy();
	testStrcat();
	return(0);
}
