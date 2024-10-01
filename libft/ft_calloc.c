#include "libft.h"

void	*ft_calloc(size_t element_count, size_t element_size)
{
	unsigned char	*d;
	size_t			max_size_t;

	max_size_t = (size_t)-1;
	if (element_size != 0 && element_count > max_size_t / element_size)
		return (NULL);
	d = (void *)malloc(element_count * element_size);
	if (!d)
		return (NULL);
	ft_bzero(d, element_count * element_size);
	return (d);
}
