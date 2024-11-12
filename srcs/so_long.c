/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:14:43 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/12 13:33:01 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	**map;
	char	filepath[256];
     if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
        return (get_error(EXTENSION_ERROR));
	ft_strlcpy(filepath, "maps/", sizeof(filepath));
	if (argc != 2)
		return (get_error(ARGUMENT_ERROR));
	ft_strlcat(filepath, argv[1], sizeof(filepath));
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (get_error(FD_ERROR));
	map = ft_get_map(fd);
	if (!map)
		return (close(fd), 1);
	launch_game(map);
    free_map(map, 0);
	close(fd);
	return (0);
}
