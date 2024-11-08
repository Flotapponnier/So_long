/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:42:48 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/07 20:01:29 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

char	**ft_get_map(int fd)
{
	char	**map;
	int		i;
	int		j;

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
	if(!ft_verif_map(map))
	{
		j = 0;
		while (j < i)
		{
			free(map[j]);
			j++;
		}
		free(map);
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
	{
		printf("Error invalid caracter \n");
		return (0);
	}
	while (map[i])
	{
		if (!is_rectangle(map[i], count_row))
		{
			printf("Error : width problem \n");
			return (0);
		}
		i++;
	}
    if(!is_edge(map))
        return (0);
	if (!ft_find_position_p(map, &col, &row))
	{
			printf("Position P not found");
			return (0);
	}
	printf("Position P found at col : %d row : %d \n \n", col, row);
    printf("THIS IS %c \n", map[row][col] );
	validate_flood(map, row, col);
    printf("\n \n");
	return (1);
}
