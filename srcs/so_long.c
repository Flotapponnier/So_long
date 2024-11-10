/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:14:43 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/10 19:14:48 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	**map;
	char	filepath[256];

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
	close(fd);
	return (0);
}
