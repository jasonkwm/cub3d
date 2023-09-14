/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:45:20 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/14 23:37:44 by nwai-kea         ###   ########.fr       */
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
	map->px = 0;
	map->py = 0;
	map->map = NULL;
}

int	init_mlx(t_variables *var)
{
	t_img	mlx;

	ft_bzero(&mlx, sizeof(mlx));
	var->screen = &mlx;
	var->screen->mlx = mlx_init();
	if (!(var->screen->mlx))
		return (1);
	var->screen->win = mlx_new_window(var->screen->mlx, (int)var->max_width,
			(int)var->max_height, "cub3d");
	var->screen->img = mlx_new_image(var->screen->mlx, (int)var->max_width,
			(int)var->max_height);
	var->screen->addr = mlx_get_data_addr(var->screen->img, &var->screen->bpp,
			&var->screen->line_length, &var->screen->endian);
	return (0);
}

void	init_raycast(t_variables *var)
{
	t_raycast	rc;

	ft_bzero(&rc, sizeof(rc));
	var->rc = rc;
	var->rc.pos_x = var->map.px;
	var->rc.pos_y = var->map.py;
	var->rc.dir_x = -1;
	var->rc.dir_y = 0;
	var->rc.plane_x = 0;
	var->rc.plane_y = 0.66;
	var->rc.speed = 0.1;
	var->rc.rot_speed = M_PI / 48;
}

void	init_variables(t_variables *variables)
{
	variables->max_width = 1920;
	variables->max_height = 1080;
	if (init_mlx(variables) == 1)
		return ;
	variables->window = NULL;
	init_raycast(variables);
	init_texture(&variables->texture);
	init_map(&variables->map);
}
