/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:29:38 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/16 12:47:15 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/read_map.h"

//Gets map size
void	ft_map_size(t_data *gameinfo)
{
	int	i;
	int	j;

	i = 0;
	while (gameinfo->map[i])
	{
		j = 0;
		while (gameinfo->map[i][j])
		{
			j++;
			if (j > gameinfo->map_width)
				gameinfo->map_width = j;
		}
		i++;
		gameinfo->map_height = i;
	}
}

/* Reads the .cub file and saves it on a linked list to keep us from reading the
file multiple times */
void	ft_read_file(char *filepath, t_data *gameinfo)
{
	int		fd;
	t_list	*map;
	char	*line;

	ft_check_file_ext(filepath, gameinfo);
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		ft_error(ERR_OPEN, gameinfo, EXIT_FAILURE);
	map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(&map, ft_lstnew(ft_strdup(line)));
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) < -1)
		ft_error(ERR_CLOSE, gameinfo, EXIT_FAILURE);
	if (!map)
		ft_error(ERR_SCENE, gameinfo, EXIT_FAILURE);
	gameinfo->map_file = map;
	ft_read_map(map, gameinfo);
}

// Loops the list and finds the line where map start/also saves the texture info
// BUG?: If file has any newline after map it considers as error of new line
void	ft_read_map(t_list *file, t_data *gameinfo)
{
	int		map_start;
	int		mid_map;
	int		line; // REMOVE

	line = 1;
	map_start = 0;
	mid_map = 0;
	while (file)
	{
		printf("Line: %d\n", line); // REMOVE
		if (!mid_map && ft_skip_line(file->content, gameinfo))
		{
			line++; // REMOVE
			file = file->next;
			map_start++;
			continue ;
		}
		else if (ft_isempty_line(file->content)) // If empty line
			ft_error(ERR_NL, gameinfo, EXIT_FAILURE);
		line++; // REMOVE
		mid_map = 1;
		file = file->next;
		gameinfo->map_height++;
	}
	if (!mid_map)
		ft_error(ERR_SCENE, gameinfo, EXIT_FAILURE);
	ft_get_map(gameinfo, map_start);
}

// Loops the list and copies the map to a char **
void	ft_get_map(t_data *gameinfo, int start)
{
	int		i;
	t_list	*tmp;

	tmp = gameinfo->map_file;
	while (start--) // Skips the file to the starting line of the map
		tmp = tmp->next;
	gameinfo->map = ft_calloc(gameinfo->map_height + 1, sizeof(*gameinfo->map));
	i = -1;
	while (tmp)
	{
		gameinfo->map[++i] = ft_strtrim(tmp->content, "\n");
		tmp = tmp->next;
	}
	ft_lstclear(&gameinfo->map_file, free);
	ft_check_map(gameinfo->map, gameinfo->map_height, gameinfo);
}
