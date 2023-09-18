/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:42:20 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/18 12:56:01 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" 

void	print_cub(t_vars *variables)
{
	int	i;

	i = -1;
	printf("-----------------CUB3D-----------------\n");
	printf("NO: %s\n", variables->texture.north);
	printf("SO: %s\n", variables->texture.south);
	printf("EA: %s\n", variables->texture.east);
	printf("WE: %s\n", variables->texture.west);
	printf("FLOOR: %i,%i,%i\n", variables->texture.floor[0],variables->texture.floor[1],variables->texture.floor[2]);
	printf("CEIL: %i,%i,%i\n", variables->texture.ceiling[0],variables->texture.ceiling[1],variables->texture.ceiling[2]);
	printf("--------------------------------------\n");
	while (variables->map.map[++i])
		printf("|%s|\n", variables->map.map[i]);
	printf("--------------------------------------\n");
}

int	main(int ac, char **av)
{
	t_vars	variables;
	
	if (ac != 2)
		exit_with_message("Invalid Number of Arguments.\n", 1);
	init_variables(&variables);
	parse_file(&variables, av[1]);

	mlx_hook(variables.window, 2, 2, key_hook, &variables);
	mlx_hook(variables.window, 17, (1L << 0), exit_on_click, &variables);
	mlx_loop(variables.mlx);
	print_cub(&variables);
	free_texture(&variables.texture);
	free_map(variables.map.map);
	system("leaks cub3d");
	return (2);
}
