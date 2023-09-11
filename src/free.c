/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:56:06 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/11 14:07:37 by jakoh            ###   ########.fr       */
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


void	free_list_map(t_list_map **list_map)
{
	t_list_map	*cur_node;
	t_list_map	*temp;

	cur_node = *list_map;
	while (cur_node)
	{
		temp = cur_node->next;
		free(cur_node->map_line);
		free(cur_node);
		cur_node = temp;
	}
}
