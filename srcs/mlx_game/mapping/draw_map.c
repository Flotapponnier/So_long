/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:00:33 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/08 17:07:46 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_data *data)
{
	int x, y;
	int img_x, img_y;
	fill_background(data, LIGHT_BROWN_COLOR);
		// Efface l'écran avant de redessiner
	y = 0;
	img_y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		img_x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->window,
					data->img_block, img_x, img_y);
			else if (data->map[y][x] == 'P')
				mlx_put_image_to_window(data->mlx, data->window,
					data->img_player, img_x, img_y);
			else if (data->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->window, data->img_exit,
					img_x, img_y);
			else if (data->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->window, data->img_coin,
					img_x, img_y);
			x++;
			img_x += data->img_width;
		}
		y++;
		img_y += data->img_height;
	}
}
