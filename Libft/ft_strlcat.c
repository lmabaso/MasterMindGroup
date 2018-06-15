#include "libft.h"
#include <stdio.h>

size_t ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t dst_len;
	size_t src_len;

	dst_len = ft_strlen(dest); 
	src_len = ft_strlen(src);

	if (n < dst_len + 1)
		return (src_len + n);
	if (n > dst_len + 1)
		ft_strncat(dest, src, n - dst_len - 1);
	return (dst_len + src_len);
}
