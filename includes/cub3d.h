/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:22:54 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/28 17:03:45 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define SPACES " \f\v\t\r\n"
# define WINDOW_HEIGHT 720
# define WINDOW_WIDTH 1280
# define CURRENT_EXIT_CODE 9
# define TEXTURE_SIZE 64
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

typedef struct s_list_map
{
	char		*map_line;
	struct s_list_map	*next;
}	t_list_map;

typedef struct s_texture
{
	void	*north;
	void	*south;
	void	*east;
	void	*west;
	int		*floor;
	int		*ceiling;
}	t_texture;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		pX;
	int		pY;
	char	facing_pos;
}	t_map;

typedef struct s_map_2d
{
	int	maxSize;
	int	tileS;
	int	pX;
	int	pY;
}	t_map_2d;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_texture	texture;
	t_map		map;
	t_map_2d	map_2d;
}	t_vars;



// inits.c

void	init_variables(t_vars *vars);
void	init_texture(t_texture *texture);
void	init_map(t_map *map);

// main_parser.c

int		parse_file(t_vars *vars, char *file_name);

// parse_textures.c

void	check_n_append(t_vars *vars, void **check, char *trimmed, char c);
void	get_texture(t_vars *vars, t_texture *tx, char *line, char first_char);
void	check_textures(t_vars *vars, void **check, char *get_path, char c);
void	check_rgb(void **check, char *texture);
void	check_texture_path(t_vars *vars, void **check, char *path);

// prase_textures_utils.c
int		miss_textures(t_texture *texture);
int		only_digits(char *str);

// parse_map.c

void	get_map(char *line, t_list_map **list_map);
void	get_map_size(t_vars *vars, t_list_map **list_map);
void	build_map(t_vars *vars, t_list_map **list_map);
void	get_map_2d_specs(t_vars *vars);

// parse_map_utils.c

void	malloc_and_fill_map(t_map *map, t_list_map **list_map);
void	strlcpy_custom(char *dst, const char *src, int size);
void	lstadd_back(t_list_map **lst, t_list_map *new);

// check_map.c
void	check_valid_characters(t_map *map);
void	check_walls(t_map *map);
void	flood_field(t_map *map, int curRow, int curCol, int *invalid);
void	flood_inside_map(t_map *map, int *invalid);

// hooks.c

int		key_hook(int keycode, t_vars *vars);
void	move_player_2d(int keycode, t_vars *vars);
void	move_camera(int keycode, t_vars *vars);

// 2d_map_display.c

void	put_player_2d(t_vars *vars);
void	put_walls_2d(t_vars *vars);
void	pixel_display(t_vars *vars, int x, int y, int pace);;

// free.c

void	free_texture(t_texture *texture);
void	free_map(char	**map);
void	free_list_map(t_list_map **list_map);

// exits.c

void	exit_with_message(char *message, int exit_code);
void	exit_program(t_vars *vars, char *message, int exit_code);
int		exit_on_click(t_vars *vars);

#endif