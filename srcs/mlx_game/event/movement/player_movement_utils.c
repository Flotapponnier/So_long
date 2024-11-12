/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:47:36 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/12 13:10:01 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_player_y(t_data *data)
{
	int	y;

	y = 0;
	while (data->map[y] != NULL)
	{
		if (find_player_x(data, y) != -1)
			return (y);
		y++;
	}
	return (-1);
}

int	find_player_x(t_data *data, int y)
{
	int	x;

	x = 0;
	while (data->map[y][x] != '\0')
	{
		if (data->map[y][x] == 'P')
			return (x);
		x++;
	}
	return (-1);
}

