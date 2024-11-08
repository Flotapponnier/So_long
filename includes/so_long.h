#ifndef SO_LONG_H
#define SO_LONG_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>
#include "libft.h"

#define MAX_LINES 100

//def MLX PART #define MAX_LINES 100
#define LIGHT_BROWN_COLOR 0xD2B48C
#define IMAGE_SIZE 120
#define LIGHT_BROWN_COLOR 0xD2B48C
#define IMAGE_SIZE 120  // Chaque image est de 120x120
#define PATH_IMG_PLAYER "./sprite/boba.png"
#define PATH_IMG_EXIT "./sprite/door.png"
#define PATH_IMG_COIN "./sprite/perle.png"
#define PATH_IMG_BLOCK "./sprite/tree.png" 

//KEY EVENT 
#define KEY_W 13  // W
#define KEY_A 0   // A
#define KEY_S 1   // S
#define KEY_D 2   // D
#define KEY_ESC 53 // Échap



typedef struct s_data {
    void *mlx;
    void *window;
    void *img_block;
    void *img_player;
    void *img_exit;
    void *img_coin;
    int img_width;
    int img_height;
    int win_width;
    int win_height;
    char **map; 
} t_data;


//PART 1
//
//Verify map
char **ft_get_map(int fd);
int ft_verif_map(char **result);
 //ismapvalid
int is_edge(char **map);
int is_rectangle(char *str, size_t width);
int is_map_correct_format(char **str);
 //floodmap
int validate_flood(char **map, int col, int row);
char **ft_flood_map(char **map, int col, int row);
 //utils
int ft_find_position_p(char **map, int *col, int *row);
char **ft_map_cpy(char **map);
void ft_print_map(char **map);
//
//PART2
//
//
int launch_game(char **mappi);
void draw_map(t_data *data);
void fill_background(t_data *data, int color);
int handle_key_event(int keycode, t_data *data);
void move_player_up(t_data *data);
void move_player_down(t_data *data);
void move_player_left(t_data *data);
void move_player_right(t_data *data);
void get_image(t_data *data);
void get_window_size(char **map, int *height, int *width, t_data *data);
void print_map(char **map);



#endif
