/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:12:48 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/09 10:39:02 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	check_first_letter(char   *line, char	*valid_set)
{
	char	c;
	char	*trimmed;

	trimmed = ft_strtrim(line, SPACES);
	if (!trimmed)
		return (0);
	c = trimmed[0];
	free(trimmed);
	if (ft_strchr(valid_set, c))
		return(c);
	return (0);
}

int		ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == '\n' || c == ' ')
		return (1);
	return (0);
}

int		miss_textures(t_texture *texture)
{
	if (!texture->north || !texture->south || !texture->east || !texture->west
		|| !texture->floor || !texture->ceiling)
		return (1);
	return (0);
}
