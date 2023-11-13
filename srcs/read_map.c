/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:29:38 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/13 11:05:09 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**ft_read_map(char *filepath, char **map)
{
	int		fd;
	char	*line;
	char	*all_lines;
	char	*temp;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening the map \n");
		exit(0);
	}
	all_lines = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = all_lines;
		all_lines = ft_strjoin(temp, line);
		free(line);
		free(temp);
	}
	close(fd);
	map = ft_split(all_lines, '\n');
	free(all_lines);
	return (map);
}
