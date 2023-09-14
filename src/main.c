/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:42:20 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/13 14:06:16 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" 

int	main(int ac, char **av)
{
	t_variables	variables;

	if (ac != 2)
		exit_with_message("Invalid Number of Arguments.\n", 1);
	init_variables(&variables);
	parse_file(&variables, av[1]);
	free_texture(&variables.texture);
	variables.mlx = mlx_init();
	variables.window = mlx_new_window(variables.mlx, WINDOW_WIDTH,
						WINDOW_HEIGHT, "Pet Puppy 3D.");
	mlx_hook(variables.window, 17, (1L << 0), exit_on_click, &variables);
	mlx_loop(variables.mlx);
	int i = -1;
	printf("--------------------------------------\n");
	while (variables.map.map[++i])
	{
		printf("|%s|\n", variables.map.map[i]);
	}
	printf("--------------------------------------\n");
	free_map(variables.map.map);
	// system("leaks cub3d");
	return (2);
}
