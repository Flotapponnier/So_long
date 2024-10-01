#include "so_long.h"

char **ft_get_map(int fd)
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
        while (j < i)
        {
            free(result[j]);
            j++;
        }
        free(result);
        return (NULL);
    }

    for (j = 0; j < i; j++)
    {
        printf("%s", result[j]);
        free(result[j]);
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

int	ft_verif_map(char **result)
{
	int i;
	size_t count_row;
	
	i = 0;
	count_row = ft_strlen(result[i]);
	if (!ft_is_valid_caracter(result)) 
		{
			printf("Error invalid caracter \n");
			return (0);
		}
	while(result[i])	
	{
		if (!ft_is_rectangle(result[i], count_row))
		{
			printf("Error : width problem \n");
			return (0);
		}
		
		i++;
	}
	return (1);
}
