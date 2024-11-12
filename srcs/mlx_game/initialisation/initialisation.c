/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:47:22 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/12 12:46:57 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_window_size(char **map, int *height, int *width, t_data *data)
{
	*height = 0;
	*width = 0;
	while (map[*height])
		(*height)++;
	if (*height > 0)
	{
		*width = ft_strlen(map[0]);
		if (map[0][*width - 1] == '\n')
			(*width)--;
	}

	data->win_width = (*width) * IMAGE_SIZE;
	data->win_height = (*height) * IMAGE_SIZE;
}

void	get_image(t_data *data)
{
	data->img_block = mlx_png_file_to_image(data->mlx, PATH_IMG_BLOCK,
			&data->img_width, &data->img_height);
	data->img_player = mlx_png_file_to_image(data->mlx, PATH_IMG_PLAYER,
			&data->img_width, &data->img_height);
	data->img_exit = mlx_png_file_to_image(data->mlx, PATH_IMG_EXIT,
			&data->img_width, &data->img_height);
	data->img_coin = mlx_png_file_to_image(data->mlx, PATH_IMG_COIN,
			&data->img_width, &data->img_height);
	data->img_floor = mlx_png_file_to_image(data->mlx, PATH_IMG_FLOOR,
			&data->img_width, &data->img_height);
}
