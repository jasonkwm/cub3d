/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwai-kea <nwai-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 09:43:46 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/17 19:48:34 by nwai-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Check if texture has been found \n
 * 			and append texture path if not.
 * 
 * @param tex texture struct
 * @param check pointer to specific texture to append
 * @param trimmed trimmed string from parent
 * @param c first character of trimmed string
 */
void	check_n_append(t_texture *tex, char **check, char *trimmed, char c)
{
	int		error;
	char	*get_path;

	error = 0;
	get_path = NULL;
	if (*check != NULL)
		error = 5;
	else if (c == 'F' || c == 'C')
		get_path = ft_strtrim(trimmed + 1, SPACES);
	else
		get_path = ft_strtrim(trimmed + 2, SPACES);
	if (error == 0 && get_path != NULL && *get_path != '\0')
		*check = get_path;
	else
	{
		free_texture(tex);
		free(trimmed);
		if (get_path)
			free(get_path);
		exit_with_message("Error: Invalid Textures\n", 6);
	}
}

void	get_texture(t_texture *texture, char *line, char first_char)
{
	char	*trimmed;

	trimmed = ft_strtrim(line, SPACES);
	if (trimmed != NULL && *trimmed != '\0')
	{
		if (first_char == 'N')
			check_n_append(texture, &texture->north, trimmed, first_char);
		else if (first_char == 'S')
			check_n_append(texture, &texture->south, trimmed, first_char);
		else if (first_char == 'E')
			check_n_append(texture, &texture->east, trimmed, first_char);
		else if (first_char == 'W')
			check_n_append(texture, &texture->west, trimmed, first_char);
		else if (first_char == 'F')
			check_n_append(texture, &texture->floor, trimmed, first_char);
		else if (first_char == 'C')
			check_n_append(texture, &texture->ceiling, trimmed, first_char);
	}
	free(trimmed);
}
