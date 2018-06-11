#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t slen;

	slen = ft_strlen(s1) + ft_strlen(s2);
	while (*s1)
		s1++;
	while (*s2)
		*s1++ = *s2++;
	*s1 = '\0';
	return (s1 - slen);
}
