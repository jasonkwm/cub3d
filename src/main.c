/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:42:20 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/08 10:58:59 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" 

int main(int ac, char **av)
{
	t_variables	variables;

	(void)variables;
	if (ac != 2)
		exit_with_message("Invalid Number of Arguments.\n", 1);
	init_variables(&variables);
	parse_map(av[1]);
	
    return 2;
}