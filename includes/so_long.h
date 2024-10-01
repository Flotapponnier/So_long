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
int ft_is_rectangle(char *str, size_t width);
int ft_verif_map(char **result);
#endif
