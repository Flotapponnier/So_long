/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_up.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:29:52 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/16 11:48:32 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_exit_condition_up(t_data *data, int y, int x)
{
	if (data->map[y - 1][x] == 'E')
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

static void	move_player_up_action(t_data *data, int y, int x)
{
	data->map[y][x] = '0';
	data->map[y - 1][x] = 'P';
	draw_map(data);
}

void	move_player_up(t_data *data)
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
	if (y > 0 && is_valid_movement(data->map[y - 1][x]))
	{
		exit_check = check_exit_condition_up(data, y, x);
		if (exit_check == 1)
			return ;
		else if (exit_check == -1)
			return ;
		move_player_up_action(data, y, x);
	}
}
