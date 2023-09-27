/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:45:20 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/27 13:02:31 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	init_variables(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WINDOW_WIDTH,
						WINDOW_HEIGHT, "Pet Puppy 3D.");
	init_texture(&vars->texture);
	init_map(&vars->map);
}
