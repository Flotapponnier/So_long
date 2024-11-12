/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:00:33 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/12 12:54:19 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void print_number_movement()
{
    static int number_movement = 0;

    ft_printf("Number move %d \n", number_movement);
    number_movement++;
}

static void	draw_tile(t_data *data, char map_char, int img_x, int img_y)
{
	if (map_char == '1')
		mlx_put_image_to_window(data->mlx, data->window, data->img_block, img_x, img_y);
	else if (map_char == 'P')
		mlx_put_image_to_window(data->mlx, data->window, data->img_player, img_x, img_y);
	else if (map_char == 'E')
		mlx_put_image_to_window(data->mlx, data->window, data->img_exit, img_x, img_y);
	else if (map_char == 'C')
		mlx_put_image_to_window(data->mlx, data->window, data->img_coin, img_x, img_y);
	else if (map_char == '0')
		mlx_put_image_to_window(data->mlx, data->window, data->img_floor, img_x, img_y);
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;
	int	img_x;
	int	img_y;


    print_number_movement();
	y = 0;
	img_y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		img_x = 0;
		while (data->map[y][x] != '\0')
		{
			draw_tile(data, data->map[y][x], img_x, img_y);
			x++;
			img_x += data->img_width;
		}
		y++;
		img_y += data->img_height;
	}
}
