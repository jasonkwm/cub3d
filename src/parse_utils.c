/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:12:48 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/09 10:48:06 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		miss_textures(t_texture *texture)
{
	if (!texture->north || !texture->south || !texture->east || !texture->west
		|| !texture->floor || !texture->ceiling)
		return (1);
	return (0);
}
