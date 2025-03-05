/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:30:47 by mekundur          #+#    #+#             */
/*   Updated: 2025/03/05 17:09:06 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_cleanup(t_scene *scene)
{
	int	i;

	i = 0;
	while (scene->lines && scene->lines[i])
	{
		printf("%s", scene->lines[i]);
		free(scene->lines[i++]);
	}
	free(scene->lines);
	printf("%s", scene->no_texture);
	free(scene->no_texture);
	printf("%s", scene->so_texture);
	free(scene->so_texture);
	printf("%s", scene->we_texture);
	free(scene->we_texture);
	printf("%s", scene->ea_texture);
	free(scene->ea_texture);
	printf("%s", scene->f_color);
	free(scene->f_color);
	printf("%s", scene->c_color);
	free(scene->c_color);
	printf("%d\n", scene->map_first_line);
	printf("%d\n", scene->map_last_line);


}

void	initialize(t_scene *scene, t_map *map)
{
	scene->col = 0;
	scene->row = 0;
	scene->lines = NULL;  
	scene->no_texture = NULL;
	scene->so_texture = NULL;
	scene->we_texture = NULL;
	scene->ea_texture = NULL;
	scene->f_color = NULL;
	scene->c_color = NULL;
	scene->del_line = 0;
	scene->map_first_line = 0;
	scene->map_last_line = 0;
	scene->map = map;
	map->player_x = 0;
	map->player_y = 0;
	map->player_o = 0;
	map->player_flag = 0;
}

int	main(int argc, char **argv)
{
	t_scene	scene;
	t_map	map;

	if (argc != 2)
	{
		printf("Please use the program as ./cub3D <scene>\n");
		return (0);
	}
	initialize(&scene, &map);
	get_scene_data(argv[1], &scene);

	ft_cleanup(&scene);
	return (0);
}

