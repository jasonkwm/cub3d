/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:11:15 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/29 11:28:59 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void	get_map_size(t_vars *vars, t_list_map **list_map)
{
	size_t		height;
	size_t		width;
	t_list_map	*current;

	height = 0;
	width = 0;
	current = *list_map;
	while (current)
	{
		if (ft_strlen(current->map_line) > width)
			width = ft_strlen(current->map_line);
		height++;
		current = current->next;
	}
	vars->map.height = (int)(height + 2);
	vars->map.width = (int)(width + 2);
}

void	get_map(char *line, t_list_map **list_map)
{
	t_list_map	*new_node;

	new_node = ft_calloc(1, sizeof(t_list_map));
	if (ft_strchr(line, '\n'))
		*ft_strchr(line, '\n') = '\0';
	new_node->map_line = ft_strdup(line);
	new_node->next = NULL;
	lstadd_back(list_map, new_node);
}

void	build_map(t_vars *vars, t_list_map **list_map)
{
	get_map_size(vars, list_map);
	malloc_and_fill_map(&vars->map, list_map);
	check_valid_characters(&vars->map);
	check_walls(&vars->map);
	get_map_2d_specs(vars);
}

void	get_map_2d_specs(t_vars *vars)
{
	float	biggest;

	if (vars->map.width > vars->map.height)
		biggest = vars->map.width;
	else
		biggest = vars->map.height;
	vars->map_2d.tile_size =  (float)(200 / biggest);
	vars->map_2d.px = vars->map.px * vars->map_2d.tile_size;
	vars->map_2d.py = vars->map.py * vars->map_2d.tile_size;
	vars->map_2d.max_size = biggest * vars->map_2d.tile_size;
}