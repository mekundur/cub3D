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

void	parse_map(t_scene *scene)
{
	int	i;
	int	j;
	t_map	*map;

	map = scene->map;
	
	i = scene->row;
	while (i-- > 0)
	{
		j = 0;
		while (scene->lines[j] && ft_is_whitespace(scene->lines[i][j]))
			j++;
		if (scene->lines[j] == 0)
			break;
		else
			scene->map_last_line = i;
	}
}
/*
void	get_orientation(t_scene *scene, t_map *map)
{
	int	i;
	
	i = scene->row;
	while (i-- > 0)
	{	
		if (ft_strchr(scene->lines[i], 'W'))
		{
			map->player_o = 'W';
			map->player_flag++;
		}
		if (ft_strchr(scene->lines[i], 'E'))
		{
			map->player_o = 'E';
			map->player_flag++;
		}
		if (ft_strchr(scene->lines[i], 'S'))
		{
			map->player_o = 'S';
			map->player_flag++;
		}
		if (ft_strchr(scene->lines[i], 'N'))
		{
			map->player_o = 'N';
			map->player_flag++;
		}
	}
}
*/
