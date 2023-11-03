/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:29:38 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/03 16:06:14 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/errors.h"
#include "../includes/map_check.h"

//Gets map size
void	ft_map_size(t_data *gameinfo)
{
	int	i;
	int	j;

	i = 0;
	while(gameinfo->map[i])
	{
		j = 0;
		while(gameinfo->map[i][j])
		{
			j++;
			if(j > gameinfo->map_width)
				gameinfo->map_width = j;
		}
		i++;
		gameinfo->map_height = i;
	}
}

//Prints the map
void	ft_map_print(char **map)
{
	int	i;

	i = 0;
	while(map[i])
	{
		ft_printf("%s\n",map[i]);
		i++;
	}
}

//Reads the map and returns a pointer to it
char	**ft_read_map(char *filepath, char **map, t_data *gameinfo)
{
	int		fd;
	char	*line;
	char	*all_lines;
	char	*temp;
	int		mid_map;

	mid_map = 0;
	ft_check_file_ext(filepath, gameinfo);
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		ft_error(ERR_OPEN, gameinfo, EXIT_FAILURE);
	}
	all_lines = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		if (ft_skip_line(fd, line, gameinfo, mid_map))
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		// after this we get map
		mid_map = 1;
		temp = all_lines;
		all_lines = ft_strjoin(temp, line);
		free(line);
		free(temp);
		line = get_next_line(fd);	// FIX: Leaks no clue how
	}
	close(fd);
	map = ft_split(all_lines, '\n');
	free(all_lines);
	ft_map_print(map);	// REMOVE: Start
	for (size_t i = 0; i < 4; i++) {
		ft_printf("%s\n", gameinfo->textures.walls[i].path);
	}
	ft_printf("%d\n", gameinfo->textures.floor);
	ft_printf("%d\n", gameinfo->textures.ceiling);	// REMOVE: End
	return (map);
}
