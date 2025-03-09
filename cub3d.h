#ifndef CUB3D_h
# define CUB3D_h

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <math.h>
# include "libft/libft.h"

typedef struct s_map_data
{
        int     row;
        int     col;
        int    *coor;
	int	player_x;
	int	player_y;
	char	player_o;
	int	player_flag;
} t_map;

typedef struct s_scene_data
{
        int     col;  
        int     row;  
        char    **lines;  
        char	*no_texture;
        char	*so_texture;
        char	*we_texture;
        char	*ea_texture;
	char	*f_color;
	char	*c_color;
        int     del_line;
        int     map_first_line;
        int     map_last_line;
	t_map	*map;
} t_scene;

void    ft_scene_init(t_scene *scene);
void	get_scene_data(char *argv, t_scene *scene);
void    parse_map(t_scene *scene);
void    ft_dda_init(t_scene *scene);
int     ft_row_count(char *argv);
void    ft_free_all(t_scene *scene);
void    ft_2dstrfree(char **str);
void	ft_error(t_scene *scene);
void    enclosed_map_check(t_scene *scene, t_map *map);


#endif
