/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:11:15 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/11 16:47:53 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	lstadd_back(t_list_map **lst, t_list_map *new)
{
	t_list_map	*temp;

	if (*lst != NULL)
	{
		temp = *lst;
		while (temp->next != NULL && temp != NULL)
			temp = temp->next;
		temp->next = new;
	}
	else
		*lst = new;
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
	variables->map.max_height = (int)(height + 2);
	variables->map.max_width = (int)(width + 2);
}

void	get_map_props(t_variables *variables, t_list_map **list_map)
{
	get_map_size(variables, list_map);
}

void	strlcpy_custom(char *dst, const char *src, int size)
{
	int	i;

	i = -1;
	while (src[++i] != 0 && i < size)
		dst[i] = src[i];
}


void	malloc_and_fill_map(t_variables *variables, t_list_map **list_map)
{
	int			height;
	int			width;
	int			i;
	t_list_map	*temp;

	i = -1;
	temp = *list_map;
	height = variables->map.max_height;
	width = variables->map.max_width;
	variables->map.map = ft_calloc(height + 1,sizeof(char *));
	variables->map.map[height] = NULL;
	while (++i < height)
	{
		variables->map.map[i] = ft_calloc(width + 1, sizeof(char));
		ft_memset(variables->map.map[i], '-', width);
		if (i > 0 && i < height -1)
		{
			strlcpy_custom(variables->map.map[i] + 1, temp->map_line, ft_strlen(temp->map_line));
			temp = temp->next;
		}
	}
}

void	build_map(t_variables *variables, t_list_map **list_map)
{
	get_map_size(variables, list_map);
	malloc_and_fill_map(variables, list_map);
}