#include "libft.h"

size_t  ft_double_ptr_len(void **str)
{
    size_t count;

    count = 0;
    while (str[count])
        count++;
    return (count);
}
