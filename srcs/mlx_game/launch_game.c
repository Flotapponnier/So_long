/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:17:38 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/16 17:45:46 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	print_map(char **map)
{
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		ft_printf("%s\n", map[y]);
		y++;
	}
	ft_printf("\n");
}

int	close_window(t_data *data)
{
	exit_game(data);
	return (0);
}

int	launch_game(char **mappi)
{
	t_data	data;
	int		map_width;
	int		map_height;

	data.map = ft_map_cpy(mappi);
	get_window_size(data.map, &map_width, &map_height, &data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (get_error(MLX_ERROR));
	get_image(&data);
	if (!data.img_block || !data.img_player || !data.img_exit || !data.img_coin)
		return (free(data.mlx), get_error(IMG_ERROR));
	data.window = mlx_new_window(data.mlx, data.win_width, data.win_height,
			"The world of Boba");
	if (!data.window)
	{
		free(data.mlx);
		return (get_error(WINDOW_ERROR));
	}
	draw_map(&data);
	mlx_key_hook(data.window, handle_key_event, &data);
	mlx_hook(data.window, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
