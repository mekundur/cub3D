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
        int             *number;
        int             *color;
        int             c;  
        int             r;  
        float   dscale;
        int             width;
        int             height;
        float   x_min;
        float   x_max;
        float   y_min;
        float   y_max;
        float   length_x;
        float   length_y;
        float   *x; 
        float   *y; 
        float   *z; 
        float   dx; 
        float   dy; 
        float   s;  
        float   x_inc;
        float   y_inc;

}       t_map;

void            ft_map_init(t_map *map);
void		*get_map_data(char *argv, t_map *map);
void            ft_dda_init(t_map *map);
int                     ft_column_count(char *argv);
int                     ft_row_count(char *argv);
void            ft_free_all(t_map *map);

#endif
