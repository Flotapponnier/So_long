/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_left.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:30:22 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/12 13:26:51 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_exit_condition_left(t_data *data, int y, int x)
{
	if (data->map[y][x - 1] == 'E')
	{
		if (is_victory(data->map))
		{
			printf("Victory!\n");
            exit_game(data);
			return (1);
		}
		else
		{
			printf("Come back when you have all the pearls\n");
			return (-1);
		}
	}
	return (0);
}

static void	move_player_left_action(t_data *data, int y, int x)
{
	data->map[y][x] = '0';
	data->map[y][x - 1] = 'P';
	draw_map(data);
}

void	move_player_left(t_data *data)
{
	int	y;
	int	x;
	int	exit_check;

	y = find_player_y(data);
	if (y == -1)
		return ;
	x = find_player_x(data, y);
	if (x == -1)
		return ;
	if (x > 0 && is_valid_movement(data->map[y][x - 1]))
	{
		exit_check = check_exit_condition_left(data, y, x);
		if (exit_check == 1) // Victory conditions met
			return ;
		else if (exit_check == -1) // Victory conditions not met
			return ;
		move_player_left_action(data, y, x);
	}
}
