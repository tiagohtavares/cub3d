/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:52:11 by heda-sil          #+#    #+#             */
/*   Updated: 2023/11/06 17:24:50 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_check.h"


// Checks if the file is a .cub file
void	ft_check_file_ext(char *file, t_data *gameinfo)
{
	char *file_ext;
	char *file_name;

	file_name = ft_strrchr(file, '/');
	if (!file_name)
	{
		file_name = file;
	}
	file_ext = ft_strrchr(file_name + 1, '.');
	if (!file_ext || (file_ext && ft_strncmp(file_ext, ".cub", 5)))
	{
		ft_error(ERR_TYPE, gameinfo, EXIT_FAILURE);
	}
}

// Checks if line contains one of the textures
bool	ft_check_textures(char *line)
{
	if (ft_strnstr(line, "NO", ft_strlen(line)))
	{
		return (true);
	}
	else if (ft_strnstr(line, "SO", ft_strlen(line)))
	{
		return (true);
	}
	else if (ft_strnstr(line, "EA", ft_strlen(line)))
	{
		return (true);
	}
	else if (ft_strnstr(line, "WE", ft_strlen(line)))
	{
		return (true);
	}
	else if (ft_strnstr(line, "C", ft_strlen(line)))
	{
		return (true);
	}
	else if (ft_strnstr(line, "F", ft_strlen(line)))
	{
		return (true);
	}
	return (false);
}

// Gets the textures from the passed line
// TODO: Check if texture line is valid and save only the path to texture instead of full line
// TODO: Similar for floor and ceiling textures, check if valid and save color
void	ft_get_textures(char *line, t_texture *textures)
{
	if (ft_strnstr(line, "NO", ft_strlen(line)))
	{
		textures->walls[N].path = ft_strdup(line);	// TMP: split to get only path
	}
	else if (ft_strnstr(line, "SO", ft_strlen(line)))
	{
		textures->walls[S].path = ft_strdup(line);
	}
	else if (ft_strnstr(line, "EA", ft_strlen(line)))
	{
		textures->walls[E].path = ft_strdup(line);
	}
	else if (ft_strnstr(line, "WE", ft_strlen(line)))
	{
		textures->walls[W].path = ft_strdup(line);
	}
	else if (ft_strnstr(line, "C", ft_strlen(line)))
	{
		textures->ceiling = 0;	//TMP: Get func to extract color
	}
	else if (ft_strnstr(line, "F", ft_strlen(line)))
	{
		textures->floor = 0;	//TMP: Get func to extract color
	}
}

// Checks if a string has no chars besides whitespaces
bool	ft_isempty_line(char *line)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '\n' && line[i] != ' ' && line[i] != '\t')
		{
			return (false);
		}
	}
	return (true);
}

// Skips all lines that don't contain map information (texture and blank line)
int	ft_skip_line(char *line, t_data *gameinfo)
{
	if (ft_isempty_line(line))	// Skips empty lines
	{
		return (1);
	}
	if (ft_check_textures(line))	// Skips texture lines
	{
		ft_get_textures(line, &gameinfo->textures);
		return (1);
	}
	return (0);
}
