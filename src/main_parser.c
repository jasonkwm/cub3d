/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:19:54 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/09 11:26:58 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Checks for valid character \n
 * 		  check if found map & check if map has ended \n
 * 		  check if map found before all texture \n
 * 
 * @param first_char first character of line read
 * @param found_map tracks map, 0 = no, 1 = yes, 2 = map ended
 * @param miss_texture tracks texture, 0 = found all texture, 1 = missing
 */
void	pre_valid_check(char first_char, int *found_map, int miss_texture)
{
	if (!ft_strchr("NSFWCE1", first_char))
		exit_with_message("Error: Invalid Map.\n", 3);
	if (first_char == '1' && *found_map == 0)
		*found_map = 1;
	if (*found_map == 2 && first_char != '\0')
		exit_with_message("Error: Invalid Map.\n", 3);
	if (first_char == '\0' && *found_map == 1)
	{
		if (*found_map == 1)
			*found_map = 2;
		return ;
	}
	else if (*found_map == 1 && first_char != '1')
	{
		exit_with_message("Error: Invalid Map.\n", 3);
	}
	if (first_char == '1' && miss_texture)
		exit_with_message("Error: Missing Texture.\n", 4);
	if (!miss_texture && ft_strchr("NSFWCE", first_char))
		exit_with_message("Error: Extra Texture.\n", 5);
}

void	analyze_line(t_variables *variables, char *line, int *found_map)
{
	char	first_char;
	char	*trimmed;
	int		miss_texture;

	trimmed = ft_strtrim(line, SPACES);
	first_char = trimmed[0];
	free(trimmed);
	miss_texture = miss_textures(&variables->texture);
	pre_valid_check(first_char, found_map, miss_texture);
	if (first_char == '\0')
		return ;
	if (miss_texture)
		get_texture(&variables->texture, line, first_char);
	else
		get_map(&variables->map, line);
}

int	parse_map(t_variables *variables, char *filename)
{
	int		fd;
	char	*line;
	int		found_map;

	found_map = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_with_message("Error: Cannot Read File.\n", 2);
	line = get_next_line(fd);
	while (line)
	{
		analyze_line(variables, line, &found_map);
		free(line);
		line = get_next_line(fd);
	}
	(void)variables;
	close(fd);
	return (0);
}