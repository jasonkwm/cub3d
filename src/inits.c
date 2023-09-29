/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:45:20 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/29 11:20:22 by jakoh            ###   ########.fr       */
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
	map->pX = 0;
	map->pY = 0;
	map->map = NULL;
}

void init_2d(t_map_2d *map_2d)
{
	map_2d->maxSize = 0;
	map_2d->tileS = 0;
	map_2d->pX = 0;
	map_2d->pY = 0;
	map_2d->pDeltaX = 0;
	map_2d->pDeltaY = 0;
	map_2d->pAngle = 0;
}
