/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:42:20 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/12 14:33:04 by jakoh            ###   ########.fr       */
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
