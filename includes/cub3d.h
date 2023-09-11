/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:22:54 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/11 13:47:09 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define SPACES " \f\v\t\r\n"
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	*floor;
	char	*ceiling;
}	t_texture;

typedef struct s_map
{
	char	**map;
	int		max_height;
	int		max_width;

}	t_map;

typedef struct s_link_map
{
	char		*map_line;
	struct s_link_map	*next;
}	t_link_map;

typedef struct s_variables
{
	void		*mlx;
	void		*window;
	t_texture	texture;
	t_map		map;
}	t_variables;

// inits.c

void	init_variables(t_variables *variables);
void	init_texture(t_texture *texture);
void	init_map(t_map *map);

// main_parser.c

int		parse_file(t_variables *variables, char *file_name);

// parse_textures.c

void	check_n_append(t_texture *tex, char **check, char *trimmed, char c);
void	get_texture(t_texture *texture, char *line, char first_char);

// parse_map.c

void	get_map(char *line, t_link_map **link_map);

// utils.c

int		miss_textures(t_texture *texture);

// free.c

void	free_texture(t_texture *texture);
void	free_map(char	**map);

// exits.c

void	exit_with_message(char *message, int exit_code);

#endif