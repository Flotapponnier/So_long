/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:54:34 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/10 12:33:32 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_top_row(char **map)
{
	int	i;

	i = 0;
	while (map[0][i] != '\n' && map[0][i] != '\0')
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_bottom_row(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
		i++;
	j = 0;
	while (map[i - 1][j] != '\n' && map[i - 1][j] != '\0')
	{
		if (map[i - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_left_column(char **map)
{
	int	i;

	i = 1;
	while (map[i] != NULL)
	{
		if (map[i][0] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_right_column(char **map)
{
	int	i;
	int	len;

	i = 1;
	while (map[i] != NULL)
	{
		len = 0;
		while (map[i][len] != '\n' && map[i][len] != '\0')
			len++;
		if (map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
