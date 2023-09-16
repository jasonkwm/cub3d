/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:33:46 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/09/17 02:51:14 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pix_draw(t_variables *var, int x, int y, int color)
{
	char	*pix;

	if (y < 0 || y > var->max_height - 1 || x < 0 || x > var->max_width - 1)
		return ;
	pix = var->screen->addr + (y * var->screen->line_length + x
			* (var->screen->bpp / 8));
	*(unsigned int *)pix = color;
}

int	path_to_img(t_img *img, char *path)
{
	img->mlx = mlx_init();
	if (!(img->mlx))
		return (1);
	if (ft_strstr(path, ".png"))
		img->img = mlx_png_file_to_image();
}

int	set_img(t_variables *var)
{
	if (path_to_img(&var->tex_img.n, var->texture.north)
		|| path_to_img(&var->tex_img.s, var->texture.south)
		|| path_to_img(&var->tex_img.e, var->texture.east)
		|| path_to_img(&var->tex_img.w, var->texture.west))
		return (1);
	free(var->texture.north);
	free(var->texture.east);
	free(var->texture.south);
	free(var->texture.west);
	return (0);
}
