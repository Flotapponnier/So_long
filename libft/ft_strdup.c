#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*cpy;
	size_t	i;

	if (!str)
		return (NULL);
	cpy = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!cpy)
		return (NULL);
	i = 0;
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
