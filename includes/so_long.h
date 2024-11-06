#ifndef SO_LONG_H
#define SO_LONG_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

#define MAX_LINES 100


//Verify map
char **ft_get_map(int fd);
int ft_verif_map(char **result);
 //ismapvalid
int is_rectangle(char *str, size_t width);
int is_map_correct_format(char **str);
 //floodmap
int validate_flood(char **map, int col, int row);
char **ft_flood_map(char **map, int col, int row);
 //utils
int ft_find_position_p(char **map, int *row, int *col);
char **ft_map_cpy(char **map);
void ft_print_map(char **map);
#endif
