/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:55:38 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/08 17:08:28 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key_event(int keycode, t_data *data)
{
	static int	nb_mouvement = 1;

	if (keycode == KEY_W)
	{
		nb_mouvement++;
		printf("NB MOVE : %d", nb_mouvement);
		move_player_up(data);
	}
	else if (keycode == KEY_A)
	{
		nb_mouvement++;
		printf("NB MOVE : %d", nb_mouvement);
		move_player_left(data);
	}
	else if (keycode == KEY_S)
	{
		printf("NB MOVE : %d", nb_mouvement);
		nb_mouvement++;
		move_player_down(data);
	}
	else if (keycode == KEY_D)
	{
		nb_mouvement++;
		printf("NB MOVE : %d", nb_mouvement);
		move_player_right(data);
	}
	else if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->window);
		exit(0);
	}
	return (0);
}
