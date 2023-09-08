/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:19:54 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/08 11:47:56 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == '\n' || c == ' ')
		return (1);
	return (0);
}

void	texture_finder(char *line)
{
	char	*found;
	
	int		i;

	i = -1;
	found = ft_strnstr(line, "NO", ft_strlen(line));
	if (found != NULL)
	{	
		found = ft_strtrim(found + 2, SPACES);
		printf("%s: %zu\n", found, ft_strlen(found));
	}
}

void	analyze_line(char *line)
{
	texture_finder(line);
}

int	parse_map(char *filename)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_with_message("Cannot Read File.\n", 2);
	line = get_next_line(fd);
	while (line)
	{
		// ft_putstr_fd(line, 1);
		analyze_line(line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}