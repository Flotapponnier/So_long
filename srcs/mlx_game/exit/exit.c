/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:16:36 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/12 13:38:51 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_data *data)
{
	free_map(data->map, 0);
	mlx_destroy_image(data->mlx, data->img_block);
	mlx_destroy_image(data->mlx, data->img_player);
	mlx_destroy_image(data->mlx, data->img_exit);
	mlx_destroy_image(data->mlx, data->img_coin);
	mlx_destroy_image(data->mlx, data->img_floor);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	free(data->mlx);
	exit(0);
}
