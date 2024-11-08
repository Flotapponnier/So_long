/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ismap_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:16:04 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/07 14:55:49 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_edge(char **map)
{
    int i = 0;
    int j = 0;

    // Check the top row (excluding the last character '\n')
    while (map[0][i] != '\n')
    {
        if (map[0][i] != '1')
        {
            printf("Error: Top row has an invalid character at position (%d, %d)\n", 0, i);
            return 0;
        }
        i++;
    }

    // Check the bottom row (excluding the last character '\n')
    i = 0;
    while (map[i] != NULL)  // Find the last row
    {
        i++;
    }
    j = 0;
    while (map[i - 1][j] != '\n')  // Check last row (bottom row)
    {
        if (map[i - 1][j] != '1')
        {
            printf("Error: Bottom row has an invalid character at position (%d, %d)\n", i - 1, j);
            return 0;
        }
        j++;
    }

    // Check the left column (excluding '\n')
    i = 1;  // Start from the second row
    while (map[i] != NULL)  // Loop through the rows
    {
        if (map[i][0] != '1')
        {
            printf("Error: Left column has an invalid character at position (%d, 0)\n", i);
            return 0;
        }
        i++;
    }

    // Check the right column (excluding '\n')
    i = 1;  // Start from the second row
    while (map[i] != NULL)  // Loop through the rows
    {
        int len = 0;
        while (map[i][len] != '\n' && map[i][len] != '\0')  // Find the length of the row
        {
            len++;
        }
        if (map[i][len - 1] != '1')  // Check the last character in the row (right edge)
        {
            printf("Error: Right column has an invalid character at position (%d, %d)\n", i, len - 1);
            return 0;
        }
        i++;
    }

    // If all checks passed
    return 1;
}

int	is_rectangle(char *str, size_t width)
{
	size_t	str_width;

	str_width = ft_strlen(str);
	if (str_width != width)
		return (0);
	return (1);
}

static int	ft_list_valid_car(char c)
{
	return (c == 'E' || c == 'P' || c == 'C' || c == '1' || c == '0'
		|| c == '\n');
}

int	is_map_correct_format(char **str)
{
	int	i;
	int	j;
	int	exit;
	int	player;
	int	coin;

	exit = 0;
	player = 0;
	coin = 0;
	i = 0;
	j = 0;
	while (str[j])
	{
		while (str[j][i])
		{
			if (str[j][i] == 'E')
				exit++;
			if (str[j][i] == 'P')
				player++;
			if (str[j][i] == 'C')
				coin++;
			if (!ft_list_valid_car(str[j][i]))
			{
				printf(" Error : Caracter : %c can't be there \n", str[j][i]);
				return (0);
			}
			i++;
		}
		i = 0;
		j++;
	}
	if (exit < 1 || player != 1 || coin < 1)
		return (0);
	return (1);
}
