#include "so_long.h"

char **ft_get_map (int fd)
{
    char **result;
    int i;
    int j;
    int valid_map;

    result = malloc(sizeof(char *) * (MAX_LINES + 1));
    if (result == NULL)
        return (NULL);
    i = 0;
    while (i < MAX_LINES)
    {
        result[i] = ft_get_next_line(fd);
        if (result[i] == NULL)
            break;
        i++;
    }
    result[i] = NULL;
    valid_map = ft_verif_map(result);
    if (!valid_map)
    {
		j = 0;
        while (j < i)
        {
            free(result[j]);
            j++;
        }
        free(result);
        return (NULL);
    }
	j = 0;
    while(j < i)
    {
        printf("%s", result[j]);
        free(result[j]);
		j++;
    }
    
    free(result);
    return (result);
}

int ft_is_rectangle(char *str, size_t width)
{
	size_t str_width;

	str_width = ft_strlen(str);
	if(str_width != width)
		return (0);
	return (1);
}

int ft_list_valid_car(char c)
{
	return ( c == 'E' || c == 'P' || c == 'C' || c == '1' || c == '0' || c == '\n');
}

int	ft_is_valid_caracter(char **str)
{
	int i;
	int j;	
	int exit;
	int player;
	int coin;

	exit = 0;
	player = 0;
	coin = 0;
	i = 0;
	j = 0;
	
	while(str[j])
	{
		while(str[j][i])
		{
			if(str[j][i] == 'E')
				exit++;
			if(str[j][i] == 'P')
				player++;
			if(str[j][i] == 'C')
				coin++;
			if(!ft_list_valid_car(str[j][i]))
			{	
				printf(" Error : Caracter : %c can't be there \n", str[j][i]);
				return (0);
			}
			i++;
		}
		i=0;
		j++;
	}	
	if(exit < 1 || player != 1 || coin < 1)
		return(0);
	return (1);
}


int ft_find_position_p(char **map, int *row, int *col)
{
	while(map[*col])
	{
		while(map[*col][*row])
		{
			if(map[*col][*row] == 'P')
			{
				return (1);			
			}
			(*row)++;
		}
		(*row) = 0;
		(*col)++;
	}
	return (0);
}

char **ft_map_cpy(char **map)
{
	int		i;
	char	**map_cpy;
	
	i = 0;
	while(map[i])
		i++;
	map_cpy = malloc(sizeof(char *) * (i + 1));
	if(!map_cpy)
		return (NULL);
	i = 0;
	while(map[i])
	{
		map_cpy[i] = ft_strdup(map[i]);
		if(!map_cpy[i])
		{
			while(i-- > 0)
			{
				free(map_cpy[i]);
			}
			free(map_cpy);
			return (NULL);
		}
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

int ft_is_flood_valid(char **map, int col, int row)
{
	if(map[col][row] == 'E' || map[col][row] == '0' || map[col][row] == 'C' )
		return (1);
	return (0);
}

char **ft_flood_map(char **map, int col, int row)
{
	if(!ft_is_flood_valid(map, col, row)
		return (map);
	map[col][row] = 'v';
	if(ft_is_flood_valid(map, col + 1 , row))
		ft_flood_map(map, col + 1, row);
	if(ft_is_flood_valid(map, col - 1 , row))
		ft_flood_map(map, col - 1, row);
	if(ft_is_flood_valid(map, col, row + 1))
		ft_flood_map(map, col, row - 1);
	if(ft_is_flood_valid(map, col, row + 1))
		ft_flood_map(map, col, row + 1);
	return (map);
}

int	ft_verif_map(char **result)
{
	int i;
	int col;
	int row;
	size_t count_row;
	char **map;

	map = ft_map_cpy(result);
	i = 0;
	col = 0;
	row = 0;
	count_row = ft_strlen(map[i]);
	if (!ft_is_valid_caracter(map)) 
		{ printf("Error invalid caracter \n");
			return (0);
		}
	while(map[i])	
	{
		if (!ft_is_rectangle(map[i], count_row))
		{
			printf("Error : width problem \n");
			return (0);
		}
		i++;
	}
	// flood fill 
	if (!ft_find_position_p(map, &col, &row))
	{
		printf("Position P not found");
		return (0);
	}
	printf("Position P found at col : %d row : %d \n", col, row);
	map = ft_flood_map(map, col, row);
	return (1);
}
