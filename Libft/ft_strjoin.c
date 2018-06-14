#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *tmp;

	if (!s1 || !s2)
		return (NULL);
	if (!(tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	return(tmp = ft_strcat(ft_strdup(s1), s2));
}
