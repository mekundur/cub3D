/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:07:44 by mekundur          #+#    #+#             */
/*   Updated: 2025/03/05 18:20:49 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_row_col(t_scene *scene)
{
	int	i;
	int	len;
	t_map	*map;

	len = 0;
	map = scene->map;
	map->row = scene->map_last_line - scene->map_first_line + 1;
	i = scene->map_first_line;
	while (i < scene->map_last_line)
	{
		len = ft_strlen(scene->lines[i]) - 1;
		// printf("len: %d\n", len);
		if (len > map->col)
			map->col = len;
		i++;
	}
}

static int	ft_is_orientation(char s)
{
	char	*directions;

	directions = "WENS";
	if (ft_strchr(directions, s))
		return (1);
	return (0);
}

void	extract_orientation_coor(t_scene *scene, int line, int i, int j)
{
	t_map	*map;

	map = scene->map;
	if (map->player_flag)
		ft_error(scene);
	map->player_flag++;
	map->player_x = i;
	map->player_y = j;
	map->player_o = scene->lines[line][j];
	printf("Player: %d %d %c\n", map->player_x, map->player_y ,map->player_o);
}

void	extract_map(t_scene *scene, t_map *map)
{
	int	i;
	int	j;
	int	k;
	int line;

	i = 0;
	line = scene->map_first_line;
	while (line < scene->map_first_line + map->row)
	{
		j = 0;
		k = 0;
		while (scene->lines[line][j] != '\n')
		{
			if (scene->lines[line][j] == '\t')
			{
				k = 0;
				while (k < 7)
				{
					map->coor[i * map->col + k] = 0;
					k++;
				}
			}
			if (ft_is_whitespace(scene->lines[line][j]))
				map->coor[i * map->col + j + k] = 0;
			else if (scene->lines[line][j] == '0')
				map->coor[i * map->col + j + k] = 0;
			else if (scene->lines[line][j] == '1')
				map->coor[i * map->col + j + k] = 1;
			else if (ft_is_orientation(scene->lines[line][j]))
				extract_orientation_coor(scene, line, i, j);
			else
				ft_error(scene);
			j++;
		}
		while (j < map->col)
		{	map->coor[i * map->col + j + k] = 0;
			j++;
		}
		// printf("j: %d\n", j);
		// printf("i: %d\n", i);
		// printf("line: %d\n", line);
		i++;
		line++;
	}
	// i = 0;
	// while (i < map->row)
	// {
	// 	j = 0;
	// 	while(j < map->col)
	// 	{
	// 		printf("%d", map->coor[i * map->col + j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
}

void	parse_map(t_scene *scene)
{
	t_map	*map;

	map = scene->map;
	// printf("%d\n", scene->map_first_line);
	// printf("%d\n", scene->map_last_line);

	map_row_col(scene);

	printf("map_row: %d\n", map->row);
	printf("map_col: %d\n", map->col);

	map->coor = (char *)ft_calloc(map->row * map->col, sizeof(char));

	extract_map(scene, map);
	if (!map->player_o)
		ft_error(scene);
	enclosed_map_check(scene, map);
}
