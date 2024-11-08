/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:14:43 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/07 20:24:01 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	int		fd;
	char	**map;
//PART 1 : validate map and return the map.
	fd = open("maps/map1.ber", O_RDONLY);
	if (!fd)
		return (1);
	map = ft_get_map(fd);
	if (!map)
	{
		close(fd);
		printf("Map incorrect");
		return (1);
	}
    int i = -1;
    while(map[++i])
        ft_printf("%s", map[i]);
//END PART 1
//
//PART 2 LAUNCH THE GAME
    launch_game(map);    
	close(fd);
	return (0); 
}
