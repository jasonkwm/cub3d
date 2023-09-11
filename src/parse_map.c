/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:11:15 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/11 14:19:22 by jakoh            ###   ########.fr       */
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
	new_node->map_line = ft_strdup(line);
	new_node->next = NULL;
	lstadd_back(list_map, new_node);
}
