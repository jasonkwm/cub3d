/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:39:47 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/27 15:26:27 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pixel_display(t_vars *vars, int x, int y, int pace);

void	put_walls(t_vars *vars)
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
				pixel_display(vars, j, i, 12);
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


void	temp_player(t_vars *vars)
{
	int	a;
	int	b;
	int	pX;
	int	pY;

	a = -1;
	pX = vars->map.pX * 12;
	pY = vars->map.pY * 12;
	while (++a < 4)
	{
		b = -1;
		while (++b < 4)
			mlx_pixel_put(vars->mlx, vars->win, pX + b, pY + a, 0xFF0000);
	}
}