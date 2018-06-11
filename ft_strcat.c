#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t s_len;
	char *tmp;
	char *s;
	
	s = (char *)s2;
	s_len = ft_strlen((const char *)s1) + ft_strlen(s2) - 2;
	if (!(tmp = (char *)malloc(s_len + 1)))
		return (NULL);
	while (*s1)
		*tmp++ = *s1++;
	while (*s)
		*s1++ = *s++;
	*s1 = '\0';
	return (s1 - s_len);
}
