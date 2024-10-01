#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc;
	unsigned char	*ptr;
	size_t			i;

	uc = (unsigned char)c;
	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == uc)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
