#include <so_long.h>

void	print_map(char **map)
{
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		printf("%s\n", map[y]);
		y++;
	}
	printf("\n");
}

int	launch_game(char **mappi)
{
	char			**map;
	t_data			data;
	int				map_width;
	int				map_height;

	map = ft_map_cpy(mappi);
	get_window_size(map, &map_width, &map_height, &data);
	data.map = map;
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		printf("Erreur: Impossible d'initialiser MiniLibX\n");
		return (1);
	}
	get_image(&data);
	if (!data.img_block || !data.img_player || !data.img_exit || !data.img_coin)
	{
		printf("Erreur: Impossible de charger une des images\n");
		return (1);
	}
	data.window = mlx_new_window(data.mlx, data.win_width, data.win_height,
			"Map Display");
	if (!data.window)
	{
		free(data.mlx);
		printf("Erreur: Impossible de créer la fenêtre\n");
		return (1);
	}
	fill_background(&data, LIGHT_BROWN_COLOR);
	draw_map(&data);
	print_map(data.map);
	mlx_key_hook(data.window, handle_key_event, &data);
	mlx_loop(data.mlx);
	return (0);
}
