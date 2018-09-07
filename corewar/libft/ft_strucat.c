#include "libft.h"

unsigned char	*ft_strucat(unsigned char *s1, const unsigned char *s2)
{
	size_t slen;

	slen = ft_strulen(s1) + ft_strulen(s2);
	s1 += ft_strulen(s1);
	while (*s2)
		*s1++ = *s2++;
	*s1 = '\0';
	return (s1 - slen);
}