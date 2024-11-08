/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapvalid_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:02:47 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/07 14:48:22 by ftapponn         ###   ########.fr       */
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

int	ft_find_position_p(char **map, int *col, int *row)
{
		while(map[*row])
		{
				while(map[*row][*col])
				{
						if(map[*row][*col] == 'P')
								return (1);
						(*col)++;
				}
				(*col) = 0;
				(*row)++;
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

