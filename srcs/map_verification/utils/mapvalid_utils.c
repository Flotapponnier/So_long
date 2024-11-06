/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapvalid_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:02:47 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/05 14:59:47 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_print_map(char **map)
{
    int i;

    i = -1;
    while(map[++i])
        printf("%s", map[i]);
    return ;
}

int	ft_find_position_p(char **map, int *row, int *col)
{
		while(map[*col])
		{
				while(map[*col][*row])
				{
						if(map[*col][*row] == 'P')
								return (1);
						(*row)++;
				}
				(*row) = 0;
				(*col)++;
		}
		return (0);
}

char	**ft_map_cpy(char **map)
{
	int		i;
	char	**map_cpy;

	i = 0;
	while (map[i])
		i++;
	map_cpy = malloc(sizeof(char *) * (i + 1));
	if (!map_cpy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		map_cpy[i] = ft_strdup(map[i]);
		if (!map_cpy[i])
		{
			while (i-- > 0)
				free(map_cpy[i]);
			free(map_cpy);
			return (NULL);
		}
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

