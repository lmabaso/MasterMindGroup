#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t s_len;

	s_len = ft_strlen(s);
	while (1)
	{
		if (s[s_len] == c)
			return ((char *)&s[s_len]);
		else if (!s_len)
			break ;
		s_len--;
	}
	return (NULL);
}
