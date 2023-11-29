/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:48:59 by heda-sil          #+#    #+#             */
/*   Updated: 2023/11/24 15:45:54 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/errors.h"

// Checks if char at pos x,y are valid
void	ft_check_pos(char *set, int x, int y, t_data *gameinfo)
{
	if (!ft_strchr(set, gameinfo->map_dup[y][x]))
	{
		gameinfo->map_dup = ft_db_free(gameinfo->map_dup);
		ft_error(ERR_WALLS, gameinfo, EXIT_FAILURE);
	}
}

int	check_floors(char *set, int x, int y, t_data *gameinfo)
{
	while (gameinfo->map_dup[y][x] && (gameinfo->map_dup[y][x] == '0' || \
	ft_strchr(PLAYER, gameinfo->map_dup[y][x])))
	{
		if (y == 1 || y == gameinfo->map_height || x == 0 || \
		x == (int)ft_strlen(gameinfo->map_dup[y]) - 2)
		{
			gameinfo->map_dup = ft_db_free(gameinfo->map_dup);
			ft_error(ERR_WALLS, gameinfo, EXIT_FAILURE);
		}
		ft_check_pos(set, x - 1, y - 1, gameinfo);
		ft_check_pos(set, x, y - 1, gameinfo);
		ft_check_pos(set, x + 1, y - 1, gameinfo);
		ft_check_pos(set, x - 1, y, gameinfo);
		ft_check_pos(set, x + 1, y, gameinfo);
		ft_check_pos(set, x - 1, y + 1, gameinfo);
		ft_check_pos(set, x, y + 1, gameinfo);
		ft_check_pos(set, x + 1, y + 1, gameinfo);
		x++;
	}
	return (x);
}

// Checks if nbr of players on map is valid
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
			if (ft_strchr(PLAYER, map[i][j]))
				player++;
		}
	}
	if (player != 1)
		ft_error(ERR_PLAYER, gameinfo, EXIT_FAILURE);
}

// Main func to check if map is good
void	ft_check_map(char **map, int height, t_data *game)
{
	int	i;
	int	j;

	game->map_dup = ft_copy_map(map, height);
	i = 0;
	j = 0;
	while (game->map_dup[i])
	{
		if (!ft_isflood_line(game->map_dup[i] + j))
		{
			i++;
			j = 0;
			continue ;
		}
		while (game->map_dup[i][j] != '0' && \
		!ft_strchr(PLAYER, game->map_dup[i][j]))
			j++;
		j = check_floors(FLOOR_CHARS, j, i, game);
	}
	game->map_dup = ft_db_free(game->map_dup);
	ft_check_player(game, game->map);
}
