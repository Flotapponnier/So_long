/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_down.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:31:40 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/12 13:37:01 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_exit_condition_down(t_data *data, int y, int x)
{
	if (data->map[y + 1][x] == 'E')
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
	int	exit_check;

	y = find_player_y(data);
	if (y == -1)
		return ;
	x = find_player_x(data, y);
	if (x == -1)
		return ;
	if (data->map[y + 1] && is_valid_movement(data->map[y + 1][x]))
	{
		exit_check = check_exit_condition_down(data, y, x);
		if (exit_check == 1)
			return ;
		else if (exit_check == -1)
			return ;
		move_player(data, y, x);
	}
}
