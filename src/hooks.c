/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:16:35 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/18 12:56:01 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// 13 = W, 0 = A, 1 = S, 2 = D
// 126 = UP, 123 = LEFT, 125 = DOWN, 124 = RIGHT
int	key_hook(int keycode, t_vars *variables)
{
	if (keycode == 53)
		exit_program(variables, "K Bye.\n", 404);
	if (keycode == 0 || keycode == 2 || keycode == 1 || keycode == 13)
		move_player(keycode, variables);
	// if (keycode == 126 || keycode == 125 || keycode == 124 || keycode == 123)
	// 	ft_move_enemy(keycode, variables);
	return (0);
}


// 13 = W, 0 = A, 1 = S, 2 = D
void	move_player(int keycode, t_vars *variables)
{
	mlx_clear_window(variables->mlx, variables->window);
	if (keycode == 13)
		variables->map.pY -= 1;
	if (keycode == 0)
		variables->map.pX -= 1;
	if (keycode == 1)
		variables->map.pY += 1;
	if (keycode == 2)
		variables->map.pX += 1;
	mlx_put_image_to_window(variables->mlx, variables->window, variables->texture.north, variables->map.pX * 32, variables->map.pY * 32);
	printf("px,py: %i, %i\n", variables->map.pX,  variables->map.pY);
}

// 126 = UP, 123 = LEFT, 125 = DOWN, 124 = RIGHT
void	move_camera(int keycode, t_vars *variables)
{
	if (keycode == 126)
		variables->map.pY += 32;
	if (keycode == 123)
		variables->map.pX -= 32;
	if (keycode == 125)
		variables->map.pY -= 32;
	if (keycode == 124)
		variables->map.pX += 32;
}
