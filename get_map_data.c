
#include "cub3d.h"

void	ft_2dstrfree(char **str)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

int	ft_coloumn_count(char *argv)
{
	int		fd;
	int		col;
	char	*line;
	char	**tmp;

	col = 0;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	tmp = ft_split(line, ' ');
	while (tmp[col])
	{
		if (!((tmp[col][0] >= '0' && tmp[col][0] <= '9') || tmp[col][0] == '-'))
			break ;
		col++;
	}
	close(fd);
	free(line);
	ft_2dstrfree(tmp);
	return (col);
}

void	put_data(t_map *map, char **str, int i, int j)
{
	if (str[j])
	{
		map->number[(i * map->c) + j] = ft_atoi(str[j]);
		map->color[(i * map->c) + j] = \
				ft_atoi_hex(ft_strnstr(str[j], "0x", 12));
		if (map->color[(i * map->c) + j] == 0)
			map->color[(i * map->c) + j] = 0xFFFFFFFF;
		else
			map->color[(i * map->c) + j] = \
				(map->color[(i * map->c) + j] << 8) + 0xFF;
	}
	else
	{
		map->number[(i * map->c) + j] = 0;
		map->color[(i * map->c) + j] = 0xFFFFFFFF;
	}
}

void	get_textures(t_map *map)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	tmp = NULL;
	while (map->lines && map->lines[i])
	{
		tmp = ft_split_wspaces(map->lines[i]);
		j = 0;
		while (tmp && tmp[j])
		{
			if (ft_strnstr(tmp[j], "NO", 2) && ft_strnstr(tmp[j + 1], "./", 2))
				map->no_texture = ft_strdup(tmp[j + 1]);
			else if (ft_strnstr(tmp[j], "SO", 2) && ft_strnstr(tmp[j + 1], "./", 2))
				map->so_texture = ft_strdup(tmp[j + 1]);
			else if (ft_strnstr(tmp[j], "WE", 2) && ft_strnstr(tmp[j + 1], "./", 2))
				map->we_texture = ft_strdup(tmp[j + 1]);
			else if (ft_strnstr(tmp[j], "EA", 2) && ft_strnstr(tmp[j + 1], "./", 2))
				map->ea_texture = ft_strdup(tmp[j + 1]);
			j++;
		}
		ft_2dstrfree(tmp);
		i++;
	}	
}

int	ft_row_count(char *argv)
{
	int		row;
	int		fd;
	char	*tmp;

	row = 0;
	tmp = NULL;
	fd = open(argv, O_RDONLY);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		free(tmp);
		row++;
	}
	close(fd);
	return (row);
}

void	get_data(char *argv, t_map *map)
{
	int		i;
	int		fd;
	// char	*line;

	map->lines = (char **)calloc(map->r + 1, sizeof(char *));
	if (!map->lines)
		return ;
	map->lines[map->r] = NULL;
	fd = open(argv, O_RDONLY);
	i = 0;
	while (i < map->r)
		map->lines[i++] = get_next_line(fd);
	close (fd);
}

void	get_colors(t_map *map)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	tmp = NULL;
	while (map->lines && map->lines[i])
	{
		tmp = ft_split_wspaces(map->lines[i]);
		j = 0;
		while (tmp && tmp[j])
		{
			if (ft_strnstr(tmp[j], "F", 1))
				map->f_color = ft_strdup(tmp[j + 1]);
			else if (ft_strnstr(tmp[j], "C", 1))
				map->c_color = ft_strdup(tmp[j + 1]);
			j++;
		}
		ft_2dstrfree(tmp);
		i++;
	}	
}

void	*get_map_data(char *argv, t_map *map)
{
//	map = (t_map *)malloc(sizeof(t_map));
//	if (!map)
//		return (0);
//	ft_map_init(map);
	map->r = ft_row_count(argv);
	printf("map_row: %d\n", map->r);
//	map->c = ft_coloumn_count(argv);
//	printf("map_col: %d\n", map->c);
//	map->number = (int *)malloc(map->c * map->r * sizeof(int));
//	map->color = (int *)malloc(map->c * map->r * sizeof(int));
//	if (!map->color || !map->number)
//		return (0);
	get_data(argv, map);
	get_textures(map);
	get_colors(map);
	return (map);
}
