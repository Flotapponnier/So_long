#include "libft.h"

static char	*ft_concatenate(const char *s1, const char *s2, char *result)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result[i] = s2[j];
		j++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size;
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	size = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_concatenate(s1, s2, result);
	return (result);
}
