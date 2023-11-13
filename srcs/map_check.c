/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:52:11 by heda-sil          #+#    #+#             */
/*   Updated: 2023/11/13 16:19:44 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_check.h"

// Checks if the file is a .cub file
void	ft_check_file_ext(char *file, t_data *gameinfo)
{
	char	*file_ext;
	char	*file_name;

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
void	ft_get_textures(char *line, t_texture *textures, t_data *gameinfo)
{
	if (ft_strnstr(line, "NO", ft_strlen(line)))
	{
		textures->walls[N].path = ft_extract_texture(line, gameinfo);
	}
	else if (ft_strnstr(line, "SO", ft_strlen(line)))
	{
		textures->walls[S].path = ft_extract_texture(line, gameinfo);
	}
	else if (ft_strnstr(line, "EA", ft_strlen(line)))
	{
		textures->walls[E].path = ft_extract_texture(line, gameinfo);
	}
	else if (ft_strnstr(line, "WE", ft_strlen(line)))
	{
		textures->walls[W].path = ft_extract_texture(line, gameinfo);
	}
	else if (ft_strnstr(line, "C", ft_strlen(line)))
	{
		textures->ceiling = ft_get_colors(line, gameinfo);
	}
	else if (ft_strnstr(line, "F", ft_strlen(line)))
	{
		textures->floor = ft_get_colors(line, gameinfo);
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
// TODO: Check for duplicate textures
// TODO: Count nbr of textures to know if all of them are specified
bool	ft_skip_line(char *line, t_data *gameinfo)
{
	if (ft_isempty_line(line)) // Skips empty lines
	{
		return (true);
	}
	else if (ft_check_textures(line)) // Skips texture lines
	{
		ft_get_textures(line, &gameinfo->textures, gameinfo);
		return (true);
	}
	return (false);
}

// Validates and extracts color values from R,G,B to int
int	ft_get_colors(char *line, t_data *gameinfo)
{
	char	**rgb;
	int		tmp;
	int		color;
	int		i;
	int		bit;

	rgb = ft_validate_colors(line, gameinfo);
	color = 0;
	bit = 18; // To work with alpha channel change to 24
	i = -1;
	while (rgb[++i] && bit >= 0)
	{
		tmp = ft_atoi(rgb[i]);
		if (tmp > 255)
		{
			ft_db_free(rgb);
			ft_error(ERR_TEXTINFO, gameinfo, EXIT_FAILURE);
		}
		color += (tmp & 0xFF) << bit;
		bit -= 8;
	}
	ft_db_free(rgb);
	return (color);
}

// Validates the color line, and color values
char	**ft_validate_colors(char *line, t_data *gameinfo)
{
	char	**rgb;
	char	*tmp;
	int		i;
	int		j;

	rgb = ft_split(line, ',');
	i = -1;
	while (rgb[++i])
	{
		tmp = ft_strtrim(rgb[i], "FC \n\t"); // Cleans color value
		free(rgb[i]);
		rgb[i] = tmp;
		j = -1;
		while (tmp[++j]) // Check if all components are digits, that will ensure that values are positive
		{
			if (!ft_isdigit(tmp[j]) || i > 2) // Check that color value only has 3 components
			{
				ft_db_free(rgb);
				ft_error(ERR_TEXTINFO, gameinfo, EXIT_FAILURE); // TODO: Change error msg
			}
		}
	}
	return (rgb);
}

char	*ft_extract_texture(char *line, t_data *gameinfo)
{
	char	*path;
	char	**splitted;
	int		i;

	splitted = ft_split(line, ' ');
	i = 0;
	while (splitted[i])
	{
		i++;
	}
	if (i != 2)
	{
		printf("line 199\n");
		ft_error(ERR_TEXTINFO, gameinfo, EXIT_FAILURE);
	}
	path = ft_strdup(splitted[1]);
	ft_db_free(splitted);
	return (path);
}
