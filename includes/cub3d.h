/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:22:54 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/12 21:36:42 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define SPACES " \f\v\t\r\n"
# define CURRENT_EXIT_CODE 9
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list_map
{
	char				*map_line;
	struct s_list_map	*next;
}						t_list_map;

typedef struct s_img
{
	void				*mlx;
	void				*img;
	void				*win;
	char				*addr;
	int					bpp;
	int					line_length;
	int					endian;
	int					width;
	int					height;
}						t_img;

typedef struct s_texture
{
	char				*north;
	char				*south;
	char				*east;
	char				*west;
	char				*floor;
	char				*ceiling;
}						t_texture;

typedef struct s_map
{
	char				**map;
	int					height;
	int					width;
	int					px;
	int					py;
}						t_map;

typedef struct s_variables
{
	double				max_width;
	double				max_height;
	t_img				*screen;
	void				*window;
	t_texture			texture;
	t_map				map;
}						t_variables;

// inits.c

void					init_variables(t_variables *variables);
void					init_texture(t_texture *texture);
void					init_map(t_map *map);

// main_parser.c

int						parse_file(t_variables *variables, char *file_name);

// parse_textures.c

void					check_n_append(t_texture *tex, char **check,
							char *trimmed, char c);
void					get_texture(t_texture *texture, char *line,
							char first_char);

// parse_map.c

void					get_map(char *line, t_list_map **list_map);
void	get_map_size(t_variables *variables,
					t_list_map **list_map);
void	build_map(t_variables *variables,
				t_list_map **list_map);

// parse_map_utils.c

void					malloc_and_fill_map(t_map *map, t_list_map **list_map);
void					strlcpy_custom(char *dst, const char *src, int size);
void					lstadd_back(t_list_map **lst, t_list_map *new);

// check_map.c
void					check_valid_characters(t_map *map);
void					check_walls(t_map *map);
void					flood_field(t_map *map, int curRow, int curCol,
							int *invalid);
void					flood_inside_map(t_map *map, int *invalid);

// utils.c

int						miss_textures(t_texture *texture);

// free.c

void					free_texture(t_texture *texture);
void					free_map(char **map);
void					free_list_map(t_list_map **list_map);

// exits.c

void					exit_with_message(char *message, int exit_code);

#endif