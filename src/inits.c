/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:45:20 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/29 11:28:57 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_variables(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WINDOW_WIDTH,
						WINDOW_HEIGHT, "Pet Puppy 3D.");
	init_texture(&vars->texture);
	init_map(&vars->map);
	init_2d(&vars->map_2d);
}

void	init_texture(t_texture *texture)
{
	texture->north = NULL;
	texture->south = NULL;
	texture->east = NULL;
	texture->west = NULL;
	texture->floor = NULL;
	texture->ceiling = NULL;
}

void	init_map(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->px = 0;
	map->py = 0;
	map->map = NULL;
}

void init_2d(t_map_2d *map_2d)
{
	map_2d->max_size = 0;
	map_2d->tile_size = 0;
	map_2d->px = 0;
	map_2d->py = 0;
	map_2d->p_delta_x = 0;
	map_2d->p_delta_y = 0;
	map_2d->p_angle = 0;
}
