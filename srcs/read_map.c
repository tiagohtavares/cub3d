/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:29:38 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/24 15:18:49 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/errors.h"

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
void	ft_read_map(t_list *file, t_data *gameinfo)
{
	int		map_start;
	int		map_end;

	map_start = 0;
	map_end = 0;
	while (file && ft_skip_line(file->content, gameinfo))
	{
		file = file->next;
		map_start++;
	}
	while (file)
	{
		if (!ft_isempty_line(file->content))
			gameinfo->map_height++;
		else
			map_end = map_start + gameinfo->map_height;
		file = file->next;
		if (file && !ft_isempty_line(file->content) && map_end)
			ft_error(ERR_NL, gameinfo, EXIT_FAILURE);
	}
	if (!map_end && !gameinfo->map_height)
		ft_error(ERR_SCENE, gameinfo, EXIT_FAILURE);
	ft_get_map(gameinfo, map_start);
}

// Loops the list and copies the map to a char **
void	ft_get_map(t_data *gameinfo, int start)
{
	int		i;
	t_list	*tmp;

	tmp = gameinfo->map_file;
	while (start--)
		tmp = tmp->next;
	gameinfo->map = ft_calloc(gameinfo->map_height + 1, sizeof(*gameinfo->map));
	i = -1;
	while (++i < gameinfo->map_height)
	{
		gameinfo->map[i] = ft_strtrim(tmp->content, "\n");
		tmp = tmp->next;
	}
	ft_lstclear(&gameinfo->map_file, free);
}
