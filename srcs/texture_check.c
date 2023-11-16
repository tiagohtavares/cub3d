/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:52:11 by heda-sil          #+#    #+#             */
/*   Updated: 2023/11/16 11:47:15 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/errors.h"
#include "../includes/texture_check.h"

// Checks if the file is a .cub file
void	ft_check_file_ext(char *file, t_data *gameinfo)
{
	char	*file_ext;
	char	*file_name;

	file_name = ft_strrchr(file, '/');
	if (!file_name)
		file_name = file;
	file_ext = ft_strrchr(file_name + 1, '.');
	if ((file_ext && ft_strncmp(file_ext, ".cub", 5)) || !file_ext)
		ft_error(ERR_TYPE, gameinfo, EXIT_FAILURE);
}

// Checks if line contains one of the textures
int	ft_check_textures(char *line)
{
	if (ft_strnstr(line, "NO", ft_strlen(line)))
		return (1);
	else if (ft_strnstr(line, "SO", ft_strlen(line)))
		return (1);
	else if (ft_strnstr(line, "EA", ft_strlen(line)))
		return (1);
	else if (ft_strnstr(line, "WE", ft_strlen(line)))
		return (1);
	else if (ft_strnstr(line, "C", ft_strlen(line)))
		return (1);
	else if (ft_strnstr(line, "F", ft_strlen(line)))
		return (1);
	return (0);
}

// Gets the textures from the passed line
void	ft_get_textures(char *line, t_texture *textures, t_data *gameinfo)
{
	if (ft_strnstr(line, "NO", ft_strlen(line)))
		textures->walls[N].path = ft_extract_texture(line, gameinfo, &textures->walls[N]);
	else if (ft_strnstr(line, "SO", ft_strlen(line)))
		textures->walls[S].path = ft_extract_texture(line, gameinfo, &textures->walls[S]);
	else if (ft_strnstr(line, "EA", ft_strlen(line)))
		textures->walls[E].path = ft_extract_texture(line, gameinfo, &textures->walls[E]);
	else if (ft_strnstr(line, "WE", ft_strlen(line)))
		textures->walls[W].path = ft_extract_texture(line, gameinfo, &textures->walls[W]);
	else if (ft_strnstr(line, "C", ft_strlen(line)))
		textures->ceiling = ft_get_colors(line, gameinfo, textures->ceiling);
	else if (ft_strnstr(line, "F", ft_strlen(line)))
		textures->floor = ft_get_colors(line, gameinfo, textures->floor);
}

char	*ft_extract_texture(char *line, t_data *gameinfo, t_wall *wall)
{
	char	*path;
	char	**splitted;
	int		i;

	if (wall->path) // If texture have already been set before, then we have a duplicate
		ft_error(ERR_TEXTDUP, gameinfo, EXIT_FAILURE);
	gameinfo->textures.nbr_txt++;
	splitted = ft_split(line, ' ');
	i = 0;
	while (splitted[i])
		i++;
	if (i != 2) // Texture strs have to be identifier + path to texture
	{
		ft_db_free(splitted);
		ft_error(ERR_TEXTINFO, gameinfo, EXIT_FAILURE);
	}
	path = ft_strtrim(splitted[1], "\n\t");
	ft_db_free(splitted);
	return (path);
}

// Validates and extracts color values from R,G,B to int
int	ft_get_colors(char *line, t_data *gameinfo, int surface)
{
	char	**rgb;
	int		color;

	if (surface != -1) // Checks if the value has already been set or not, if yes we have duplicated
		ft_error(ERR_TEXTDUP, gameinfo, EXIT_FAILURE);
	gameinfo->textures.nbr_txt++;
	rgb = ft_validate_colors(line, gameinfo);
	color = ft_create_rgb(rgb, gameinfo);
	ft_db_free(rgb);
	return (color);
}

// Validates the color line, and color values
char	**ft_validate_colors(char *line, t_data *gameinfo)
{
	char	**rgb;
	char	*tmp;
	int		i;

	rgb = ft_split(line, ',');
	i = -1;
	while (rgb[++i])
	{
		tmp = ft_strtrim(rgb[i], "FC \n\t"); // Cleans color value
		free(rgb[i]);
		rgb[i] = tmp;
		if (!ft_isallnumeric(rgb[i]))
		{
			ft_db_free(rgb);
			ft_error(ERR_TEXTINFO, gameinfo, EXIT_FAILURE); // TODO: Change error msg
		}
	}
	if (i != 3)
	{
		ft_db_free(rgb);
		ft_error(ERR_TEXTINFO, gameinfo, EXIT_FAILURE); // TODO: Change error msg
	}
	return (rgb);
}
