/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ismap_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:16:04 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/10 12:48:39 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_edge(char **map)
{
	return (check_top_row(map) && check_bottom_row(map)
		&& check_left_column(map) && check_right_column(map));
}

int	is_rectangle(char *str, size_t width)
{
	size_t	str_width;

	str_width = ft_strlen(str);
	if (str_width != width)
		return (0);
	return (1);
}

static int	ft_list_valid_car(char c)
{
	return (c == 'E' || c == 'P' || c == 'C' || c == '1' || c == '0'
		|| c == '\n');
}

void	init_map_info(t_map_info *map_info)
{
	map_info->exit = 0;
	map_info->player = 0;
	map_info->coin = 0;
	map_info->i = 0;
	map_info->j = 0;
}

int	is_map_correct_format(char **str)
{
	t_map_info	map_info;

	init_map_info(&map_info);
	while (str[map_info.j])
	{
		while (str[map_info.j][map_info.i])
		{
			if (str[map_info.j][map_info.i] == 'E')
				map_info.exit++;
			if (str[map_info.j][map_info.i] == 'P')
				map_info.player++;
			if (str[map_info.j][map_info.i] == 'C')
				map_info.coin++;
			if (!ft_list_valid_car(str[map_info.j][map_info.i]))
				return (0);
			map_info.i++;
		}
		map_info.i = 0;
		map_info.j++;
	}
	if (map_info.exit < 1 || map_info.player != 1 || map_info.coin < 1)
		return (0);
	return (1);
}
