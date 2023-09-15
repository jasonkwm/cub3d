/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:45:20 by nwai-kea          #+#    #+#             */
/*   Updated: 2023/09/16 01:50:26 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	background(t_variables *var)
{
	int	y;
	int	color;

	y = 0;
	color = var->texture.ceiling;
}

void	draw_img(t_variables *var)
{
	int	x;

	background(var);
	x = 0;
	while (x < var->map.width)
	{

	}
}