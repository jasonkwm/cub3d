/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:42:20 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/27 11:51:59 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" 

void	mini_main(t_vars *vars);
void	print_cub(t_vars *vars);

int	main(int ac, char **av)
{
	t_vars	vars;
	
	if (ac != 2)
		exit_with_message("Invalid Number of Arguments.\n", 1);
	init_variables(&vars);
	parse_file(&vars, av[1]);
	mini_main(&vars);
	// mlx_hook(vars.window, 2, 2, key_hook, &vars);
	// mlx_hook(vars.window, 17, (1L << 0), exit_on_click, &vars);
	// mlx_loop(vars.mlx);
	print_cub(&vars);
	free_texture(&vars.texture);
	free_map(vars.map.map);
	system("leaks cub3d");
	return (2);
}

void	mini_main(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->window,
		vars->texture.north, vars->map.pX * 32, vars->map.pY * 32);
	mlx_hook(vars->window, 2, 2, key_hook, vars);
	mlx_hook(vars->window, 17, (1L << 0), exit_on_click, vars);
	mlx_loop(vars->mlx);
}

// create a put map function to put a 2d map 

void	print_cub(t_vars *vars)
{
	int	i;

	i = -1;
	printf("-----------------CUB3D-----------------\n");
	printf("NO: %s\n", vars->texture.north);
	printf("SO: %s\n", vars->texture.south);
	printf("EA: %s\n", vars->texture.east);
	printf("WE: %s\n", vars->texture.west);
	printf("FLOOR: %i,%i,%i\n", vars->texture.floor[0],
			vars->texture.floor[1],vars->texture.floor[2]);
	printf("CEIL: %i,%i,%i\n", vars->texture.ceiling[0],
			vars->texture.ceiling[1],vars->texture.ceiling[2]);
	printf("--------------------------------------\n");
	while (vars->map.map[++i])
		printf("|%s|\n", vars->map.map[i]);
	printf("--------------------------------------\n");
}