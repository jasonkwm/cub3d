/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:45:20 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/09/17 02:20:04 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_color(int t, char *clr)
{
	int	r;
	int	g;
	int	b;

	r = clr[0];
	g = clr[1];
	b = clr[2];
	return (t << 24 | r << 16 | g << 8 | b);
}

void	background(t_variables *var)
{
	int	x;
	int	y;

	x = 0;
	while (x < var->max_width)
	{
		y = 0;
		if (y < var->max_height)
		{
			if (y < var->max_height / 2)
				pix_draw(var, x, y, create_color(0, var->texture.ceiling));
			else
				pix_draw(var, x, y, create_color(0, var->texture.floor));
			y++;
		}
		++x;
	}
}

int	draw_texture(t_variables *var, char *img, int x)
{
}

void	draw_img(t_variables *var)
{
	int	x;

	background(var);
	set_imgs(var);
	x = 0;
	while (x < var->max_width)
	{
		ray_pos(var, x);
		ray_len(&var->rc);
		dda(var);
		set_projection(var);
		if (var->rc.side == 0 && var->rc.step_x == 1)
			draw_texture(var, var->texture.north, x);
		if (var->rc.side == 0 && var->rc.step_x == -1)
			draw_texture(var, var->texture.south, x);
		if (var->rc.side == 1 && var->rc.step_x == 1)
			draw_texture(var, var->texture.east, x);
		if (var->rc.side == 1 && var->rc.step_x == -1)
			draw_texture(var, var->texture.west, x);
		x++;
	}
}
