/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:48:59 by heda-sil          #+#    #+#             */
/*   Updated: 2023/11/16 13:31:09 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/errors.h"

// Checks if all elements of line is belongs to set of chars
int	ft_valid_chars(char *line, char *set)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (!ft_strchr(set, line[i]))
			return (0);
	}
	return (1);
}

// Cheks first and last map line
void	ft_check_extremes(char *line, t_data *gameinfo)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (!ft_strchr(" 1", line[i]))
			ft_error(ERR_WALLS, gameinfo, EXIT_FAILURE);
	}
}

// Cheks mid map lines
// Logic works but have to do this recursive
// Idea is for each type of valid map character we recursive verify all 8 chars arround it and check if they belong to the allowed set of chars e.g. for '1' everything is allowed, for ' ' only [' ', '1'], for '0' only ['1', '0', 'PLAYER'] for player ['0', '1'] etc
void	ft_check_middle(char **map, int y, t_data *gameinfo)
{
	int	i;

	i = -1;
	while (map[y][++i])
	{
		if (map[y][i] == ' ' && i < gameinfo->map_height - 1 && i != 0) // TMP: i verification here is temp just so we dont go out of boundaries, we need to change this for a recursive approach
		{
			if (!ft_strchr(" 1", map[y][i + 1]) || !ft_strchr(" 1", map[y + 1][i]) || !ft_strchr(" 1", map[y][i - 1]) || !ft_strchr(" 1", map[y - 1][i]) || !ft_strchr(" 1", map[y - 1][i + 1]) || !ft_strchr(" 1", map[y - 1][i - 1]) || !ft_strchr(" 1", map[y + 1][i + 1]) || !ft_strchr(" 1", map[y + 1][i - 1]))
				printf("ERROR\n");
		}
	}
	(void)gameinfo;
}

// Main func to check if map is good, surrounded by walls, only one player, only allowed chars etc
void	ft_check_map(char **map, int height, t_data *gameinfo)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if (i == 0 || i == height - 1)
			ft_check_extremes(map[i], gameinfo);
		else
			ft_check_middle(map, i, gameinfo);

	}
}
