/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:22:54 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/07 15:12:44 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_texture {
    char    *north;
    char    *south;
    char    *east;
    char    *west;
}   t_texture;

typedef struct s_color {
    char    *floor;
    char    *ceiling;
}   t_color;

typedef struct s_map {
    char    **map;
    int     max_height;
    int     max_width;

}   t_map;

typedef struct s_map_info
{
    t_texture   texture;
    t_color     color;
    t_map		map;
}   t_map_info;

typedef struct s_variables
{
	void	*mlx;
	void	*window;
	t_map_info	map_info;	
}	t_variables;


// exits.c
void	exit_with_message(char *message, int exit_code);

//parse_map.c
int parse_map (char *file_name);

#endif