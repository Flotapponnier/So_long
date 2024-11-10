/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:58:48 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/08 17:07:39 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_background(t_data *data, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			mlx_pixel_put(data->mlx, data->window, x, y, color);
			x++;
		}
		y++;
	}
}
