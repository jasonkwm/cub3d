/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:16:35 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/28 16:59:42 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// 13 = W, 0 = A, 1 = S, 2 = D
// 126 = UP, 123 = LEFT, 125 = DOWN, 124 = RIGHT
int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit_program(vars, "K Bye.\n", 404);
	if (keycode == 0 || keycode == 2 || keycode == 1 || keycode == 13)
		move_player(keycode, vars);
	// if (keycode == 126 || keycode == 125 || keycode == 124 || keycode == 123)
	// 	ft_move_enemy(keycode, vars);
	return (0);
}


// 13 = W, 0 = A, 1 = S, 2 = D
void	move_player(int keycode, t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	put_walls_2d(vars);
	if (keycode == 13)
			vars->map_2d.pY -= vars->map_2d.tileS / 2;
	if (keycode == 0)
			vars->map_2d.pX -= vars->map_2d.tileS / 2;
	if (keycode == 1)
			vars->map_2d.pY += vars->map_2d.tileS / 2;
	if (keycode == 2)
			vars->map_2d.pX += vars->map_2d.tileS / 2;
		put_player_2d(vars);
	printf("px,py: %i, %i\n", vars->map_2d.pX,  vars->map_2d.pY);
}

// 126 = UP, 123 = LEFT, 125 = DOWN, 124 = RIGHT
void	move_camera(int keycode, t_vars *vars)
{
	if (keycode == 126)
		vars->map.pY += 32;
	if (keycode == 123)
		vars->map.pX -= 32;
	if (keycode == 125)
		vars->map.pY -= 32;
	if (keycode == 124)
		vars->map.pX += 32;
}
