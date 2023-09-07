/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:19:54 by jakoh             #+#    #+#             */
/*   Updated: 2023/09/07 15:19:31 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int parse_map (char *file_name) {
    // open readonly file
    // gnl that shit
    // check line that has been gnl
    int     fd;
    int     i;
    char    **gnl_store;
    char    *line;

    i = 0;
    fd = open(file_name, O_RDONLY);
    if (fd == -1)
        exit_with_message("Cannot Read File.\n", 2);
    line = get_next_line(fd);
    while (line) {
        // do something here
        return 1;
    }
    return 0;
}