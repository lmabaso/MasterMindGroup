#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t n_len;

	if (!strcmp(needle, ""))
		return ((char *)haystack);
	n_len = ft_strlen(needle);
	while (*haystack)
	{
		if (*haystack == *needle)
			if (strncmp(haystack, needle, n_len) == 0)
				return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
