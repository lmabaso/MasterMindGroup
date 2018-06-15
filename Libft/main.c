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
	size_t len1;
	size_t len2;

	len1 = strlen(strcat(s1, s2));
	len2 = strlen(ft_strcat(s3, s4));
	printf("strcat: %s\t%zu\n", strcat(s1, s2), len1);
	printf("ft_strcat: %s\t%zu\n", ft_strcat(s3, s4), len2);
}

void	testStrlcat(int n)
{
	//char s1[50] = "BMW";
	//char s2[] = "Volvo";	
	char s3[50] = "BMW";
	char s4[] = "Volvo";
	
	//size_t len;
	size_t len2;
	
	//len = strlcat(s1, s2, n);
	//printf("strlcat:\n");
	//printf("s1 = %s\t%zu\n", s1, len);
	len2 = ft_strlcat(s3, s4, n);
	printf("ft_strlcat:\n");
	printf("s3 = %s\t%zu\n", s3, len2);
}

void	testStrsplit(void)
{
	char	*str = ",,,JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,,,,,SEP,,,OCT,NOV,DEC,,,,,";
	char	**array;
	int i;

	array = ft_strsplit(str, ',');
	i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
}

void	testItoa(void)
{
	printf("%s\n", ft_itoa (12345678));
}

int		main(int c, char ** v)
{
	if (c == 1)
		;
	/*testMemset();
	testBzero();
	testMemcpy();
	testMemccpy();*/
	//testStrcat();
	//testStrlcat(atoi(v[1]));
	//testStrsplit();
	testItoa();
	return(0);
}
