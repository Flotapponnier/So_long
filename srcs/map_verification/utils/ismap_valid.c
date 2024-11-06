/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ismap_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:16:04 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/05 12:23:56 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
