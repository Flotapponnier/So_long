#include "libft.h"

int	ft_lstsize(t_list *list)
{
	t_list	*start;
	int		count;

	start = list;
	count = 0;
	while (start)
	{
		count++;
		start = start->next;
	}
	return (count);
}
