/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:29:38 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/06 17:43:04 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_map.h"

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

//Reads the .cub file and saves it on a linked list to keep us from reading the file multiple times
void	ft_read_file(char *filepath, t_data *gameinfo)
{
	int		fd;
	t_list	*map;
	char	*line;

	ft_check_file_ext(filepath, gameinfo);
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		ft_error(ERR_OPEN, gameinfo, EXIT_FAILURE);
	}
	map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(&map, ft_lstnew(ft_strdup(line)));
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	gameinfo->map_file = map;
	ft_read_map(map, gameinfo);
}

// Loops the list and finds the line where map start/also saves the texture info
void	ft_read_map(t_list *file, t_data *gameinfo)
{
	int		map_start;
	int		mid_map;

	map_start = 1;
	mid_map = 0;
	while (file)
	{
		if (ft_skip_line(file->content, gameinfo) && !mid_map)
		{
			file = file->next;
			map_start++;
			continue ;
		}
		else if (ft_skip_line(file->content, gameinfo) && mid_map)	// If empty line
		{
			ft_error(ERR_NL, gameinfo, EXIT_FAILURE);
		}
		mid_map = 1;
		gameinfo->map_height++;
		file = file->next;
	}
	ft_get_map(gameinfo, map_start);
}


// Loops the list and copies the map to a char **
void	ft_get_map(t_data *gameinfo, int start)
{
	int		i;
	t_list	*tmp;
	char	*map;

	tmp = gameinfo->map_file;
	while (start-- > 1)	// Skips the file to the starting line of the map
	{
		tmp = tmp->next;
	}
	gameinfo->map = ft_calloc(gameinfo->map_height + 1, sizeof(*gameinfo->map));
	i = -1;
	while (tmp)
	{
		map = ft_strtrim(tmp->content, "\n");
		gameinfo->map[++i] = ft_strdup(map);
		free(map);
		tmp = tmp->next;
	}
	ft_lstclear(&gameinfo->map_file, free);
}
