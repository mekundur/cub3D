#include "cub3d.h"

void	ft_cleanup(t_map *map)
{
	int	i;

	i = 0;
	while (map->lines && map->lines[i])
	{
		printf("%s", map->lines[i]);
		free(map->lines[i++]);
	}
	free(map->lines);
	printf("%s", map->no_texture);
	free(map->no_texture);
	printf("%s", map->so_texture);
	free(map->so_texture);
	printf("%s", map->we_texture);
	free(map->we_texture);
	printf("%s", map->ea_texture);
	free(map->ea_texture);
	printf("%s", map->f_color);
	free(map->f_color);
	printf("%s", map->c_color);
	free(map->c_color);

}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		printf("Please use the program as ./cub3D <map>\n");
		return (0);
	}
	get_map_data(argv[1], &map);

	ft_cleanup(&map);
	return (0);
}

