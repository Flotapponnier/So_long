/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_down.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:31:40 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/12 12:55:51 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(t_data *data, int y, int x)
{
	data->map[y][x] = '0';
	data->map[y + 1][x] = 'P';
	draw_map(data);
}

void	move_player_down(t_data *data)
{
	int	y;
	int	x;

	y = find_player_y(data);
	if (y == -1)
		return ;
	x = find_player_x(data, y);
	if (x == -1)
		return ;
	if (data->map[y + 1] && is_valid_movement(data->map[y + 1][x]))
	{
		if (check_exit_condition(data, y, x))
			return ;
		move_player(data, y, x);
	}
}
