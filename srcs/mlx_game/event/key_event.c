/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:55:38 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/12 12:50:02 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key_event(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		move_player_up(data);
	else if (keycode == KEY_A)
		move_player_left(data);
	else if (keycode == KEY_S)
		move_player_down(data);
	else if (keycode == KEY_D)
		move_player_right(data);
	else if (keycode == KEY_ESC || keycode == KEY_CLOSE)
	{
		mlx_destroy_window(data->mlx, data->window);
		exit(0);
	}
	return (0);
}
