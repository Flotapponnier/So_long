#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	last_occurence;

	i = 0;
	last_occurence = -1;
	while (str[i])
	{
		if (str[i] == (char)c)
			last_occurence = i;
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(str + i));
	if (last_occurence == -1)
		return (NULL);
	return ((char *)(str + last_occurence));
}
