/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_move_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:22:35 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/08 16:44:27 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_valid_movement(char target)
{
    return (target == '0' || target == 'C' || target == 'E');
}

int is_victory(char **map)
{
    int y = 0;
    int x;

    while (map[y] != NULL)
    {
        x = 0;
        while (map[y][x] != '\0')
        {
            if (map[y][x] == 'C') 
            {
                return 0;
            }
            x++;
        }
        y++;
    }
    return 1;
}
