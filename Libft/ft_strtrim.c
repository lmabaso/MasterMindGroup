#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t len;
	size_t start;

	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	start = 0;
	while (ft_isspace(s[start]))
		start++;
	while (ft_isspace(s[len]))
		len--;
	return (!s[start] ? "" : ft_strsub(s, start, len - start + 1));
}
