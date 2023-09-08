/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:19:54 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/08 16:45:50 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	get_texture(t_texture *texture,char *line, char	first_char)
{
	char	*trimmed;

	trimmed = ft_strtrim(line, SPACES);
	if (trimmed != NULL && *trimmed != '\0')
	{
		if (first_char == 'N')
			texture->north = ft_strtrim(trimmed + 2, SPACES);
		else if (first_char == 'S')
			texture->south = ft_strtrim(trimmed + 2, SPACES);
		else if (first_char == 'E')
			texture->east = ft_strtrim(trimmed + 2, SPACES);
		else if (first_char == 'W')
			texture->west = ft_strtrim(trimmed + 2, SPACES);
		else if (first_char == 'F')
			texture->floor = ft_strtrim(trimmed + 1, SPACES);
		else if (first_char == 'C')
			texture->ceiling = ft_strtrim(trimmed + 1, SPACES);
	}
	free(trimmed);
}

// void	get_map(t_map *map, char *line)
// {

// }

void	analyze_line(t_variables *variables, char *line, int *found_map)
{
	char	first_char;
	char	*trimmed;
	int		missing_texture;

	trimmed = ft_strtrim(line, SPACES);
	first_char = trimmed[0];
	free(trimmed);
	if (!ft_strchr("NSFWCE1", first_char))
		exit_with_message("Invalid Map\n", 3);
	if (first_char == '1' && *found_map == 0)
		*found_map = 1;
	if (*found_map == 2 && first_char != '\0')
		exit_with_message("Invalid Map\n", 3);
	if (first_char == '\0')
	{
		if (*found_map == 1)
			*found_map = 2;
		return ;
	}
	missing_texture = missing_textures(&variables->texture);
	if (first_char == '1' && missing_texture)
		exit_with_message("Invalid Map.\n", 4);
	if (missing_texture)
		get_texture(&variables->texture, line, first_char);
	
}

int	parse_map(t_variables *variables, char *filename)
{
	int		fd;
	char	*line;
	int		found_map;

	found_map = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_with_message("Cannot Read File.\n", 2);
	line = get_next_line(fd);
	while (line)
	{
		// ft_putstr_fd(line, 1);
		analyze_line(variables, line, &found_map);
		free(line);
		line = get_next_line(fd);
	}
	(void)variables;
	close(fd);
	return (0);
}