/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:51:01 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/08 17:08:34 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Move player up
void	move_player_up(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == 'P')
			{
				if (y > 0 && is_valid_movement(data->map[y - 1][x]))
				{
					// Check if the player has reached the exit (E) before moving
					if (data->map[y - 1][x] == 'E')
					{
						if (is_victory(data->map))
							// Check if victory condition is met
						{
							printf("Victory!\n");
							return ; // Exit after victory
						}
					}
					else
					{
						// Move player
						data->map[y][x] = '0';
						data->map[y - 1][x] = 'P';
						draw_map(data);
						print_map(data->map);
					}
				}
				return ;
			}
			x++;
		}
		y++;
	}
}

// Move player left
void	move_player_left(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == 'P')
			{
				if (x > 0 && is_valid_movement(data->map[y][x - 1]))
				{
					// Check if the player has reached the exit (E) before moving
					if (data->map[y][x - 1] == 'E')
					{
						if (is_victory(data->map))
							// Check if victory condition is met
						{
							printf("Victory!\n");
							return ; // Exit after victory
						}
					}
					// Move player
					else
					{
						data->map[y][x] = '0';
						data->map[y][x - 1] = 'P';
						draw_map(data);
						print_map(data->map);
					}
				}
				return ;
			}
			x++;
		}
		y++;
	}
}

// Move player down
void	move_player_down(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == 'P')
			{
				if (data->map[y + 1] && is_valid_movement(data->map[y + 1][x]))
				{
					// Check if the player has reached the exit (E) before moving
					if (data->map[y + 1][x] == 'E')
					{
						if (is_victory(data->map))
							// Check if victory condition is met
						{
							printf("Victory!\n");
							return ; // Exit after victory
						}
					}
					else
					{
						// Move player
						data->map[y][x] = '0';
						data->map[y + 1][x] = 'P';
						draw_map(data);
						print_map(data->map);
					}
				}
				return ;
			}
			x++;
		}
		y++;
	}
}

// Move player right
void	move_player_right(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == 'P')
			{
				if (is_valid_movement(data->map[y][x + 1]))
				{
					// Check if the player has reached the exit (E) before moving
					if (data->map[y][x + 1] == 'E')
					{
						if (is_victory(data->map))
							// Check if victory condition is met
						{
							printf("Victory!\n");
							return ; // Exit after victory
						}
					}
					else
					{
						// Move player
						data->map[y][x] = '0';
						data->map[y][x + 1] = 'P';
						draw_map(data);
						print_map(data->map);
					}
				}
				return ;
			}
			x++;
		}
		y++;
	}
}
