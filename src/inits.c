/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:45:20 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/12 22:13:14 by nwai-kea         ###   ########.fr       */
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

// void	init_screen(t_img *screen)
// {
// 	screen->addr = 0;
// 	screen->bpp = 0;
// 	screen->endian = 0;
// 	screen->height = 0;
// 	screen->img = 0;
// 	screen->line_length = 0;
// 	screen->mlx = 0;
// 	screen->width = 0;
// 	screen->win = 0;
// }

int	init_mlx(t_variables *var)
{
	var->screen->mlx = mlx_init();
	if (!(var->screen->mlx))
		return (1);
	var->screen->win = mlx_new_window(var->screen->mlx, var->max_width,
			var->max_height, "cub3d");
	var->screen->img = mlx_new_image(var->screen->mlx, var->max_width,
			var->max_height);
	var->screen->addr = mlx_get_data_addr(var->screen->img, &var->screen->bpp,
			&var->screen->line_length, &var->screen->endian);
	return (0);
}

void	init_variables(t_variables *variables)
{
	variables->max_width = 1920;
	variables->max_height = 1080;
	if (init_mlx(variables) == 1)
		return ;
	variables->window = NULL;
	init_texture(&variables->texture);
	init_map(&variables->map);
}
