#include <so_long.h>

void fill_background(t_data *data, int color)
{
    int x = 0;
    int y = 0;

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

void draw_map(t_data *data)
{
    int x, y;
    int img_x, img_y;

    fill_background(data, LIGHT_BROWN_COLOR);  // Efface l'écran avant de redessiner
    y = 0;
    img_y = 0;
    while (data->map[y] != NULL)
    {
        x = 0;
        img_x = 0;
        while (data->map[y][x] != '\0')
        {
            if (data->map[y][x] == '1')
                mlx_put_image_to_window(data->mlx, data->window, data->img_block, img_x, img_y);
            else if (data->map[y][x] == 'P')
                mlx_put_image_to_window(data->mlx, data->window, data->img_player, img_x, img_y);
            else if (data->map[y][x] == 'E')
                mlx_put_image_to_window(data->mlx, data->window, data->img_exit, img_x, img_y);
            else if (data->map[y][x] == 'C')
                mlx_put_image_to_window(data->mlx, data->window, data->img_coin, img_x, img_y);

            x++;
            img_x += data->img_width;
        }
        y++;
        img_y += data->img_height;
    }
}

void print_map(char **map)
{
    int y = 0;

    while (map[y] != NULL)
    {
        printf("%s\n", map[y]);
        y++;
    }
    printf("\n");
}

void get_window_size(char **map, int *height, int *width, t_data *data)
{
    *height = 0;
    *width = 0;

    while (map[*height])
        (*height)++;
    if((*height) > 0)
        *width = strlen(map[0]);
    data->win_width = (*width) * IMAGE_SIZE;
    data->win_height = (*height) * IMAGE_SIZE;
}

void get_image(t_data *data)
{
    data->img_block = mlx_png_file_to_image(data->mlx, PATH_IMG_BLOCK, &data->img_width, &data->img_height);
    data->img_player = mlx_png_file_to_image(data->mlx, PATH_IMG_PLAYER, &data->img_width, &data->img_height);
    data->img_exit = mlx_png_file_to_image(data->mlx, PATH_IMG_EXIT, &data->img_width, &data->img_height);
    data->img_coin = mlx_png_file_to_image(data->mlx, PATH_IMG_COIN, &data->img_width, &data->img_height);
}

// Déplacement vers le haut
void move_player_up(t_data *data)
{
    int x = 0;
    int y = 0;

    while (data->map[y] != NULL)
    {
        x = 0;
        while (data->map[y][x] != '\0')
        {
            if (data->map[y][x] == 'P')
            {
                if (y > 0 && data->map[y - 1][x] == '0')
                {
                    data->map[y][x] = '0';
                    data->map[y - 1][x] = 'P';
                    draw_map(data);
                    print_map(data->map);
                }
                return;
            }
            x++;
        }
        y++;
    }
}

// Déplacement vers la gauche
void move_player_left(t_data *data)
{
    int x = 0;
    int y = 0;

    while (data->map[y] != NULL)
    {
        x = 0;
        while (data->map[y][x] != '\0')
        {
            if (data->map[y][x] == 'P')
            {
                if (x > 0 && data->map[y][x - 1] == '0')
                {
                    data->map[y][x] = '0';
                    data->map[y][x - 1] = 'P';
                    draw_map(data);
                    print_map(data->map);
                }
                return;
            }
            x++;
        }
        y++;
    }
}

// Déplacement vers le bas
void move_player_down(t_data *data)
{
    int x = 0;
    int y = 0;

    while (data->map[y] != NULL)
    {
        x = 0;
        while (data->map[y][x] != '\0')
        {
            if (data->map[y][x] == 'P')
            {
                if (data->map[y + 1] && data->map[y + 1][x] == '0')
                {
                    data->map[y][x] = '0';
                    data->map[y + 1][x] = 'P';
                    draw_map(data);
                    print_map(data->map);
                }
                return;
            }
            x++;
        }
        y++;
    }
}

void move_player_right(t_data *data)
{
    int x = 0;
    int y = 0;

    while (data->map[y] != NULL)
    {
        x = 0;
        while (data->map[y][x] != '\0')
        {
            if (data->map[y][x] == 'P')
            {
                if (data->map[y][x + 1] == '0')
                {
                    data->map[y][x] = '0';
                    data->map[y][x + 1] = 'P';
                    draw_map(data);
                    print_map(data->map);
                }
                return;
            }
            x++;
        }
        y++;
    }
}

int handle_key_event(int keycode, t_data *data)
{
    if (keycode == KEY_W)
        move_player_up(data);
    else if (keycode == KEY_A)
        move_player_left(data);
    else if (keycode == KEY_S)
        move_player_down(data);
    else if (keycode == KEY_D)
        move_player_right(data);
    else if (keycode == KEY_ESC)
    {
        mlx_destroy_window(data->mlx, data->window);
        exit(0);
    }
    return (0);
}

int launch_game(char **mappi)
{
    char **map = ft_map_cpy(mappi);
    t_data data;
    int map_width;
    int map_height;

    get_window_size(map, &map_width, &map_height, &data);
    data.map = map;
    data.mlx = mlx_init();
    if (!data.mlx)
    {
        printf("Erreur: Impossible d'initialiser MiniLibX\n");
        return 1;
    }
    get_image(&data);
    if (!data.img_block || !data.img_player || !data.img_exit || !data.img_coin)
    {
        printf("Erreur: Impossible de charger une des images\n");
        return 1;
    }
    data.window = mlx_new_window(data.mlx, data.win_width, data.win_height, "Map Display");
    if (!data.window)
    {
        free(data.mlx);
        printf("Erreur: Impossible de créer la fenêtre\n");
        return 1;
    }
    fill_background(&data, LIGHT_BROWN_COLOR);
    draw_map(&data);
        print_map(data.map);  
    mlx_key_hook(data.window, handle_key_event, &data); 
    mlx_loop(data.mlx);  

    return (0);
}
