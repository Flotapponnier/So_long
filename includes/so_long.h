/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:27:17 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/12 12:44:59 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX_LINES 100

// def MLX PART #define MAX_LINES 100
# define LIGHT_BROWN_COLOR 0xD2B48C
# define IMAGE_SIZE 120
# define LIGHT_BROWN_COLOR 0xD2B48C
# define IMAGE_SIZE 120 // Chaque image est de 120x120
# define PATH_IMG_PLAYER "./sprite/boba.png"
# define PATH_IMG_EXIT "./sprite/door.png"
# define PATH_IMG_COIN "./sprite/perle.png"
# define PATH_IMG_BLOCK "./sprite/tree.png"
# define PATH_IMG_FLOOR "./sprite/floor.png"

// KEY EVENT
# define KEY_W 13   // W
# define KEY_A 0    // A
# define KEY_S 1    // S
# define KEY_D 2    // D
# define KEY_ESC 53 // Échap
# define KEY_CLOSE 17

// ERROR HANDLING
# define FD_ERROR 1
# define FORMAT_ERROR 2
# define RECTANGLE_ERROR 3
# define EDGE_ERROR 4
# define P_POSITION_ERROR 5
# define FLOOD_ERROR 6
# define MLX_ERROR 7
# define IMG_ERROR 8
# define WINDOW_ERROR 9
# define ARGUMENT_ERROR 10

typedef struct s_map_info
{
	int		exit;
	int		player;
	int		coin;
	int		i;
	int		j;
}			t_map_info;

typedef struct s_data
{
	void	*mlx;
	void	*window;
	void	*img_block;
	void	*img_player;
	void	*img_exit;
	void	*img_coin;
    void    *img_floor;
	int		img_width;
	int		img_height;
	int		win_width;
	int		win_height;
	char	**map;
}			t_data;

typedef struct s_player_stat
{
	int		number_coin;
}			t_player_stat;

// PART 1
//
// Verify map
char		**ft_get_map(int fd);
int			ft_verif_map(char **result);
// ismapvalid
int			is_edge(char **map);
int			is_rectangle(char *str, size_t width);
int			is_map_correct_format(char **str);
// floodmap
int			validate_flood(char **map, int col, int row);
char		**ft_flood_map(char **map, int col, int row);
// utils
int			ft_find_position_p(char **map, int *col, int *row);
char		**ft_map_cpy(char **map);
void		ft_print_map(char **map);
int			free_map(char **map, int errnumber);
// check row
int			check_top_row(char **map);
int			check_bottom_row(char **map);
int			check_left_column(char **map);
int			check_right_column(char **map);

//
// PART2
//
//
int			launch_game(char **mappi);
void		draw_map(t_data *data);
void		fill_background(t_data *data, int color);

// event
int			handle_key_event(int keycode, t_data *data);
int			is_valid_movement(char target);
int			is_victory(char **map);
int			find_player_y(t_data *data);
int			find_player_x(t_data *data, int y);
int			check_exit_condition(t_data *data, int y, int x);

// movement
void		move_player_up(t_data *data);
void		move_player_down(t_data *data);
void		move_player_left(t_data *data);
void		move_player_right(t_data *data);

// initialisation
void		get_image(t_data *data);
void		get_window_size(char **map, int *height, int *width, t_data *data);
void		print_map(char **map);

// error
int			get_error(int errnum);

#endif
