/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_check_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:54:00 by heda-sil          #+#    #+#             */
/*   Updated: 2023/11/16 11:02:50 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/errors.h"
#include "../includes/texture_check.h"

// Checks if a string has no chars besides whitespaces
int	ft_isempty_line(char *line)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '\n' && line[i] != ' ' && line[i] != '\t')
		{
			return (0);
		}
	}
	return (1);
}

// Check if all components are digits, that will ensure that values are positive
int	ft_isallnumeric(char *rgb)
{
	int	j;
	j = -1;
	if (ft_strlen(rgb) == 0)
	{
		return (0);
	}
	while (rgb[++j])
	{
		if (!ft_isdigit(rgb[j]))
		{
			return (0);
		}
	}
	return (1);
}

// Skips all lines that don't contain map information (texture and blank line)
// TODO: Check for duplicate textures
// TODO: Count nbr of textures to know if all of them are specified
int	ft_skip_line(char *line, t_data *gameinfo)
{
	if (ft_isempty_line(line)) // Skips empty lines
	{
		return (1);
	}
	else if (gameinfo->textures.nbr_txt < 6 && ft_check_textures(line)) // Skips texture lines
	{
		ft_get_textures(line, &gameinfo->textures, gameinfo);
		return (1);
	}
	else if (gameinfo->textures.nbr_txt < 6)
	{
		ft_error(ERR_TEXTMISS, gameinfo, EXIT_FAILURE);
	}
	return (0);
}

// Converts a [R],[G],[B],[NULL] array of strs to an int
int	ft_create_rgb(char **rgb, t_data *gameinfo)
{
	int		tmp;
	int		i;
	int		color;
	int		bit;

	color = 0;
	bit = 16;
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
	return (color);
}
