/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:26:16 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/29 11:28:26 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_walls(t_map *map)
{
	int	invalid;

	invalid = 0;
	flood_field(map, 0, 0, &invalid);
	if (invalid > 0)
		exit_with_message("Invalid Map.\n", 9);
	flood_inside_map(map, &invalid);
}


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
			{
				player++;
				map->px = j;
				map->py = i;
				map->facing_pos = map->map[i][j];
			}
		}
	}
	if (player == 0 || player > 1)
		exit_with_message("Invalid Number of Players.\n", 8);
}

void	flood_inside_map(t_map *map, int *invalid)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == ' ')
				flood_field(map, i, j, invalid);
		}
	}
}

void	flood_field(t_map *map, int curCol, int curRow, int *invalid)
{
	if (curRow < 0 || curRow >= map->width || curCol < 0
		|| curCol >= map->height)
		return ;
	if (map->map[curCol][curRow] == '-' || map->map[curCol][curRow] == '1')
		return ;
	if (!ft_strchr("- 1", map->map[curCol][curRow]))
		*invalid += 1;
	if (*invalid > 0)
		return ;
	map->map[curCol][curRow] = '-';
	flood_field(map, curCol - 1, curRow, invalid);
	flood_field(map, curCol + 1, curRow, invalid);
	flood_field(map, curCol, curRow + 1, invalid);
	flood_field(map, curCol, curRow - 1, invalid);
}
