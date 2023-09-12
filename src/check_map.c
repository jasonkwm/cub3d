/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:26:16 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/12 13:27:54 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_valid_characters(t_map *map)
{
	int		player;
	int		i;
	int		j;
	
	i = -1;
	player = 0;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (!ft_strchr(" 01NSEW", map->map[i][j]))
				exit_with_message("Invalid Character in Map.\n", 7);
			else if (ft_strchr("NSEW", map->map[i][j]))
				player++;
		}
	}
	if (player == 0 || player > 1)
		exit_with_message("Invalid Number of Players.\n", 8);
}