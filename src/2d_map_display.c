/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:39:47 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/29 11:06:45 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pixel_display(t_vars *vars, int x, int y, int pace);

void	put_walls_2d(t_vars *vars)
{
	char	**map = vars->map.map;
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '1')
				pixel_display(vars, j, i, vars->map_2d.tileS);
		}
	}
}

void	pixel_display(t_vars *vars, int x, int y, int pace)
{
	int	a;
	int	b;

	a = -1;
	while (++a < pace)
	{
		b = -1;
		while (++b < pace)
			mlx_pixel_put(vars->mlx, vars->win, (x * (pace + 1)) + b, (y * (pace + 1)) + a, 0xFFFFFF);
	}
}


void	put_player_2d(t_vars *vars)
{
	float	a;
	float	b;
	float	pX;
	float	pY;

	a = -1;
	pX = vars->map_2d.pX;
	pY = vars->map_2d.pY;
	while (++a < 4)
	{
		b = -1;
		while (++b < 4)
			mlx_pixel_put(vars->mlx, vars->win, pX + b , pY + a, 0xFF0000);
	}
}