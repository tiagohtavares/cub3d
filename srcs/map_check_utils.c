/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:43:22 by heda-sil          #+#    #+#             */
/*   Updated: 2023/11/24 15:27:53 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/errors.h"

// Checks if the file is a .cub file
void	ft_check_file_ext(char *file, t_data *gameinfo)
{
	char	*file_ext;
	char	*file_name;

	file_name = ft_strrchr(file, '/');
	if (!file_name)
		file_name = file;
	else
		file_name += 1;
	file_ext = ft_strrchr(file_name + 1, '.');
	if ((file_ext && ft_strncmp(file_ext, ".cub", 5)) || !file_ext)
		ft_error(ERR_TYPE, gameinfo, EXIT_FAILURE);
}

// Checks if all elements of line is belongs to set of chars
int	ft_valid_chars(char **map, char *set)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (!ft_strchr(set, map[i][j]))
				return (0);
	}
	return (1);
}

// Creates a copy of the map padded with '#'
char	**ft_copy_map(char **map, int height)
{
	char	**map_copy;
	int		top_size;
	int		bottom_size;
	int		i;

	map_copy = NULL;
	top_size = ft_strlen(map[0]);
	bottom_size = ft_strlen(map[height - 1]);
	map_copy = ft_calloc(height + 3, sizeof(*map_copy));
	map_copy[0] = ft_calloc(top_size + 2, sizeof(*map_copy[0]));
	ft_memset(map_copy[0], '#', top_size + 1);
	i = -1;
	while (map[++i])
		map_copy[i + 1] = ft_strjoin(map[i], "#");
	map_copy[height + 1] = ft_calloc(bottom_size + 2, sizeof(char));
	ft_memset(map_copy[height + 1], '#', bottom_size + 1);
	return (map_copy);
}

int	ft_isflood_line(char *line)
{
	if (!ft_strchr(line, '0') && !ft_strchr(line, 'N'))
	{
		if (!ft_strchr(line, 'S') && !ft_strchr(line, 'W'))
		{
			if (!ft_strchr(line, 'E'))
			{
				return (0);
			}
		}
	}
	return (1);
}
