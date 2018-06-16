#include "libft.h"
#include <ctype.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!ft_strcmp(needle, ""))
		return ((char *)haystack);
	if (ft_strlen(haystack) < ft_strlen(needle))
		return (NULL);
	while (len--)
	{
		if (!needle)
			break ;
		if (*haystack == *needle)
			if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
				return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
