/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:27:00 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/10 11:14:32 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include "so_long.h"

int get_error(int errnum) 
{
    int current_line;
    char *line;
    int fd;

    current_line = 1;
    fd = open("srcs/error/error.txt", O_RDONLY);
    if (fd < 0)
        return ft_printf("Error\n Failed to open file descriptor.\n");
    line = NULL;
    while ((line = get_next_line(fd)) != NULL) 
    {
        if (current_line == errnum) 
        {
            ft_printf("Error\n %s", line);
            free(line);
            close(fd);
            return (0); 
        }
        free(line);
        current_line++;
    }
    ft_printf("Error\n Error number %d not found in error file.\n", errnum);
    close(fd);
    return (1); 
}

