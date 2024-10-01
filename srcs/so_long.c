#include "so_long.h"

int main(void)
{
	int fd;
	char **map;

	fd = open("maps/map1.ber", O_RDONLY);
	if (!fd)
		return (1);
	map = ft_get_map(fd);
	if(!map)
	{
		close(fd);
		printf("Map incorrect");
		return (1);
	}
	close(fd);
	return (0);
}
