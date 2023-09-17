/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:42:20 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/17 20:47:57 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	destroy_window(t_variables *var)
{
	free_texture(&var->texture);
	free_map(var->map.map);
	mlx_destroy_window(var->screen.mlx, var->screen.win);
	exit(0);
	return (1);
}

int	main(int ac, char **av)
{
	t_variables	variables;

	// int			i;
	if (ac != 2)
		exit_with_message("Invalid Number of Arguments.\n", 1);
	ft_bzero(&variables, sizeof(variables));
	init_variables(&variables);
	parse_file(&variables, av[1]);
	// printf("%s %s\n", variables.texture.floor, variables.texture.east);
	// printf("%c\n", variables.map.map[variables.map.py][variables.map.px]);
	mlx_hook(variables.screen.win, 17, 0, &destroy_window, &variables);
	mlx_loop(variables.screen.mlx);
	// i = 0;
	// printf("--------------------------------------\n");
	// while (variables.map.map[i])
	// {
	// 	printf("%s\n", variables.map.map[i]);
	// 	i++;
	// }
	// printf("--------------------------------------\n");
	// system("leaks cub3d");
	return (2);
}
