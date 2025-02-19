#include "cub3d.h"


int	main(int argc, char **argv)
{
	int	fd;
	t_map	map;

	if (argc != 2)
	{
		printf("Please use the program as ./cub3D <map>\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	get_map_data(argv[1], &map);

	return (0);
}

