/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:34:42 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/07 14:38:09 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_is_flood_valid(char **map, int col, int row)
{
	if (map[col][row] == 'E' || map[col][row] == '0' || map[col][row] == 'C' || map[col][row] == 'P')
		return (1);
	return (0);
}

char	**ft_flood_map(char **map, int col, int row)
{
	if (!ft_is_flood_valid(map, col, row))
		return (map);
	map[col][row] = 'v';
	if (ft_is_flood_valid(map, col + 1, row))
		ft_flood_map(map, col + 1, row);
	if (ft_is_flood_valid(map, col - 1, row))
		ft_flood_map(map, col - 1, row);
	if (ft_is_flood_valid(map, col, row + 1))
		ft_flood_map(map, col, row + 1);
	if (ft_is_flood_valid(map, col, row - 1))
		ft_flood_map(map, col, row - 1);

	return (map);
}


int validate_flood(char **map, int col, int row)
{
    int i;
    int j;

    map = ft_flood_map(map, col, row);
    ft_print_map(map);
    i = 0;
    j = 0;
    while(map[i])
    {
        while(map[i][j])
        {
            if(map[i][j] != '1' && map[i][j] != 'v' && map[i][j] != '\n')
            {
                printf("Error map flooding fail");
                printf(" Caracter %c ", map[i][j]);
                return (0);
            }
            j++;
        }
        j = 0;
        i++;
    }
    return (1);
}
