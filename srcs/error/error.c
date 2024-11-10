/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:27:00 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/10 18:53:35 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_error_line(int fd, int errnum, char **line)
{
	int	current_line;

	current_line = 1;
	*line = get_next_line(fd);
	while (*line != NULL)
	{
		if (current_line == errnum)
			return (1);
		free(*line);
		current_line++;
		*line = get_next_line(fd);
	}
	return (0);
}

int	get_error(int errnum)
{
	int		fd;
	char	*line;

	fd = open("srcs/error/error.txt", O_RDONLY);
	line = NULL;
	if (fd < 0)
	{
		ft_printf("Error\n Failed to open file descriptor.\n");
		return (1);
	}
	if (get_error_line(fd, errnum, &line))
	{
		ft_printf("Error\n %s", line);
		free(line);
		close(fd);
		return (0);
	}
	ft_printf("Error\n Error number %d not found in error file.\n", errnum);
	close(fd);
	return (1);
}
