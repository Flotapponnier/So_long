/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_right.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:32:29 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/12 18:40:41 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_exit_condition_right(t_data *data, int y, int x)
{
	if (data->map[y][x + 1] == 'E')
	{
		if (is_victory(data->map))
		{
			ft_printf("Victory!\n");
			exit_game(data);
			return (1);
		}
		else
		{
			ft_printf("Come back when you have all the pearls\n");
			return (-1);
		}
	}
	return (0);
}

static void	move_player_right_action(t_data *data, int y, int x)
{
	data->map[y][x] = '0';
	data->map[y][x + 1] = 'P';
	draw_map(data);
}

void	move_player_right(t_data *data)
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
	if (is_valid_movement(data->map[y][x + 1]))
	{
		exit_check = check_exit_condition_right(data, y, x);
		if (exit_check == 1)
			return ;
		else if (exit_check == -1)
			return ;
		move_player_right_action(data, y, x);
	}
}
