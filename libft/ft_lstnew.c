#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*add;

	add = (t_list *)malloc(sizeof(t_list));
	if (!add)
		return (NULL);
	add->content = content;
	add->next = NULL;
	return (add);
}
