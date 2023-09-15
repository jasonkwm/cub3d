/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:11:15 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/16 01:50:33 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_map_size(t_variables *variables, t_list_map **list_map)
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
	variables->map.height = (int)(height + 2);
	variables->map.width = (int)(width + 2);
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

void	rotate(t_variables *var, double rad)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = var->rc.dir_x;
	old_plane_x = var->rc.plane_x;
	var->rc.dir_x = var->rc.dir_x * cos(rad) - var->rc.dir_y * sin(rad);
	var->rc.dir_y = old_dir_x = sin(rad) + var->rc.dir_y * cos(rad);
	var->rc.plane_x = var->rc.plane_x * cos(rad) - var->rc.plane_y * sin(rad);
	var->rc.plane_y = old_plane_x * sin(rad) + var->rc.plane_y * cos(rad);
	draw_img(var);
}

int	spawn_point(t_variables *var)
{
	double	rad;

	rad = 0;
	if (var->map.pos == 'N')
		return (0);
	else if (var->map.pos == 'E')
		rad = M_PI / 2;
	else if (var->map.pos == 'S')
		rad = M_PI;
	else if (var->map.pos == 'W')
		rad = M_PI * 1.5;
	rotate(var, rad);
	return (0);
}

int	build_map(t_variables *variables, t_list_map **list_map)
{
	get_map_size(variables, list_map);
	malloc_and_fill_map(&variables->map, list_map);
	check_valid_characters(&variables->map);
	check_walls(&variables->map);
	if (!parse_rgb(variables->texture.ceiling, variables->rc.rgb_c) || !parse_rgb(variables->texture.floor, variables->rc.rgb_f))
		return (1);
	spawn_point(variables);
	return (0);
}
