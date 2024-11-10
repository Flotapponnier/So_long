/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:42:48 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/10 15:36:57 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

char	**ft_get_map(int fd)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (MAX_LINES + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < MAX_LINES)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			break ;
		i++;
	}
	map[i] = NULL;
	if (!ft_verif_map(map))
	{
		free_map(map, 0);
		return (NULL);
	}
	return (map);
}

int	ft_verif_map(char **result)
{
	int		i;
	int		col;
	int		row;
	size_t	count_row;
	char	**map;

	map = ft_map_cpy(result);
	i = 0;
	col = 0;
	row = 0;
	count_row = ft_strlen(map[i]);
	if (!is_map_correct_format(map))
		return (free_map(map, FORMAT_ERROR));
	while (map[++i])
	{
		if (!is_rectangle(map[i], count_row))
			return (free_map(map, RECTANGLE_ERROR));
	}
	if (!is_edge(map))
		return (free_map(map, EDGE_ERROR));
	if (!ft_find_position_p(map, &col, &row))
		return (free_map(map, P_POSITION_ERROR));
	if (!validate_flood(map, row, col))
		return (free_map(map, FLOOD_ERROR));
	return (1);
}
