/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:56:06 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/09 12:05:54 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_texture(t_texture *texture)
{
	if (texture->north)
		free(texture->north);
	if (texture->south)
		free(texture->south);
	if (texture->east)
		free(texture->east);
	if (texture->west)
		free(texture->west);
	if (texture->floor)
		free(texture->floor);
	if (texture->ceiling)
		free(texture->ceiling);
}

void	free_map(char	**map)
{
	int	i;

	if (!map)
		return ;
	i = -1;
	while (map[++i] != NULL)
		free(map[i]);
	free(map);
}
