/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:41:42 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/18 12:56:01 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_with_message(char *message, int exit_code)
{
	ft_putstr_fd(message, 2);
	system("leaks cub3d");
	exit(exit_code);
}

void	exit_program(t_vars *variables, char *message, int exit_code)
{
	mlx_destroy_window(variables->mlx, variables->window);
	exit_with_message(message, exit_code);
}

int	exit_on_click(t_vars *variables)
{
	exit_program(variables, "K Bye.\n", 404);
	return (1);
}