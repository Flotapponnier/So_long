/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:42:48 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/05 16:03:54 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_get_map(int fd)
{
	char	**result;
	int		i;
	int		j;
	int		valid_map;

	result = malloc(sizeof(char *) * (MAX_LINES + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < MAX_LINES)
	{
		result[i] = ft_get_next_line(fd);
		if (result[i] == NULL)
			break ;
		i++;
	}
	result[i] = NULL;
	valid_map = ft_verif_map(result);
	if (!valid_map)
	{
		j = 0;
		while (j < i)
		{
			free(result[j]);
			j++;
		}
		free(result);
		return (NULL);
	}
	j = 0;
	while (j < i)
	{
		printf("%s", result[j]);
		free(result[j]);
		j++;
	}
	free(result);
	return (result);
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
	if (!ft_find_position_p(map, &col, &row))
	{
			printf("Position P not found");
			return (0);
	}
	printf("Position P found at col : %d row : %d \n \n", col, row);
	validate_flood(map, col, row);
    printf("\n \n");
	return (1);
}
