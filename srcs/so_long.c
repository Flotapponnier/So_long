/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:14:43 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/10 15:15:35 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	int		fd;
	char	**map;

	// PART 1 : validate map and return the map.
	fd = open("maps/map1.ber", O_RDONLY);
    if (fd < 0)
		return (get_error(FD_ERROR));
	map = ft_get_map(fd);
	if (!map)
		return (close(fd), 1);
	// END PART 1
	//
	// PART 2 LAUNCH THE GAME
    launch_game(map);
	close(fd);
	return (0);
}
