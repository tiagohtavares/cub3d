/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:48:59 by heda-sil          #+#    #+#             */
/*   Updated: 2023/11/20 17:22:53 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/errors.h"
#include "../includes/debug.h"

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

// Checks if char at pos x,y are valid
int	ft_check_pos(char *set, int x, int y, t_data *gameinfo)
{
	// if (!ft_strchr("# 01NSWE", gameinfo->map[y][x]))
		// ft_error(ERR_CHAR, gameinfo, EXIT_FAILURE);
	if (!ft_strchr(set, gameinfo->map_copy[y][x]))
		return (0);
	return (1);
}

// Sets the allowed chars to be arround a specific position
char *ft_set_allowed_chars(char c)
{
	char *set;

	set = NULL;
	if (c == ' ')
		set = "# 1";
	else if (c == '1')
		set = "# 01NSWE";
	else if (c == '0')
		set = "01NOSWE";
	else if (ft_strchr("NSWE", c))
		set = "01";
	else if (c == '#')
		set = "# 1";
	return (set);
}

// Flood fill to validate map
// TODO: Fix issues for when lines are different sizes (not all pos around a char will be check so we could have cases where map is not closed)
void	flood_fill(char *set, int x, int y, t_data *gameinfo) // BUG: Wont work for cases where one line is longer than up or down line
{
	if (x < 0 || y < 0 || y >= gameinfo->map_height + 2 || x >= (int)ft_strlen(gameinfo->map_copy[y]))
		return ;
	if (gameinfo->map_copy[y][x] == '*')
		return ;
	if (!ft_check_pos(set, x, y, gameinfo))
		ft_error(ERR_MAP, gameinfo, EXIT_FAILURE);
	set = ft_set_allowed_chars(gameinfo->map_copy[y][x]);
	gameinfo->map_copy[y][x] = '*';
	flood_fill(set, x - 1, y, gameinfo);
	flood_fill(set, x, y - 1, gameinfo);
	flood_fill(set, x - 1, y + 1, gameinfo);
	flood_fill(set, x - 1, y - 1, gameinfo);
	flood_fill(set, x + 1, y + 1, gameinfo);
	flood_fill(set, x + 1, y - 1, gameinfo);
	flood_fill(set, x, y + 1, gameinfo);
	flood_fill(set, x + 1, y, gameinfo);
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

// Checks if nbr of players on map is valid | it could also set the player orientation
void	ft_check_player(t_data *gameinfo, char **map)
{
	int		i;
	int		j;
	int		player;

	i = -1;
	player = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NSWE", map[i][j]))
				player++;
		}
	}
	if (player != 1)
		ft_error(ERR_PLAYER, gameinfo, EXIT_FAILURE);
}

// Main func to check if map is good, surrounded by walls, only one player, only allowed chars etc
void	ft_check_map(char **map, int height, t_data *gameinfo)
{
	int		i;
	int		top_size;
	int		bottom_size;

	top_size = ft_strlen(map[0]);
	bottom_size = ft_strlen(map[height - 1]);
	gameinfo->map_copy = ft_calloc(height + 3, sizeof(*gameinfo->map_copy));
	gameinfo->map_copy[0] = ft_calloc(top_size + 2, sizeof(char));
	ft_memset(gameinfo->map_copy[0], '#', top_size + 1);
	gameinfo->map_copy[height + 1] = ft_calloc(bottom_size + 2, sizeof(char));
	ft_memset(gameinfo->map_copy[height + 1], '#', bottom_size + 1);
	i = -1;
	while (map[++i])
		gameinfo->map_copy[i + 1] = ft_strjoin(map[i], "#");
	// ft_check_extremes(map[0], gameinfo); // Checks first line
	// ft_check_extremes(map[height - 1], gameinfo); // Checks last line
	flood_fill(ft_set_allowed_chars(gameinfo->map[0][0]), 0 , 0, gameinfo); // TODO: Test better but it should check all the map
	ft_check_player(gameinfo, gameinfo->map); // checks nbr of players
}
