#include "libft.h"
#include <stdio.h>

size_t ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t dst_len;
	size_t src_len;
	size_t len;

	dst_len = ft_strlen(dest); 
	src_len = ft_strlen(src);
	len = dst_len + src_len;

	//if (n > dst_len + 1|| !dst_len)
	//	exit(-1);
	ft_strncat(dest, src, n - len);
	if (n <= dst_len + 1)
		return (src_len + (n - dst_len - 1));
	return (n - dst_len - 1);
}
