/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_up.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:29:52 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/10 18:41:23 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_exit_condition_up(t_data *data, int y, int x)
{
	if (data->map[y - 1][x] == 'E' && is_victory(data->map))
	{
		printf("Victory!\n");
		return (1);
	}
	return (0);
}

static void	move_player_up_action(t_data *data, int y, int x)
{
	data->map[y][x] = '0';
	data->map[y - 1][x] = 'P';
	draw_map(data);
	print_map(data->map);
}

void	move_player_up(t_data *data)
{
	int	y;
	int	x;

	y = find_player_y(data);
	if (y == -1)
		return ;
	x = find_player_x(data, y);
	if (x == -1)
		return ;
	if (y > 0 && is_valid_movement(data->map[y - 1][x]))
	{
		if (check_exit_condition_up(data, y, x))
			return ;
		move_player_up_action(data, y, x);
	}
}
