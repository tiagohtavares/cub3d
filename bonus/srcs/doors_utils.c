/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:29:57 by heda-sil          #+#    #+#             */
/*   Updated: 2023/12/08 12:59:23 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/errors.h"

int	check_door_vertical(t_data *game, int x, int y)
{
	if (game->map_dup[y - 1][x] == '1' && game->map_dup[y + 1][x] == '1')
	{
		if (game->map_dup[y][x - 1] == '1' || \
		game->map_dup[y][x + 1] == '1' || \
		game->map_dup[y][x - 1] == 'D' || \
		game->map_dup[y][x + 1] == 'D')
		{
			game->map_dup = ft_db_free(game->map_dup);
			ft_error(ERR_DOOR, game, EXIT_FAILURE);
		}
		if (game->map_dup[y][x - 1] == ' ' || game->map_dup[y][x + 1] == ' ')
			ft_error(ERR_WALLS, game, EXIT_FAILURE);
		return (1);
	}
	return (0);
}

int	check_door_horizontal(t_data *game, int x, int y)
{
	if (game->map_dup[y][x - 1] == '1' && game->map_dup[y][x + 1] == '1')
	{
		if (game->map_dup[y - 1][x] == '1' || \
		game->map_dup[y + 1][x] == '1' || \
		game->map_dup[y - 1][x] == 'D' || \
		game->map_dup[y + 1][x] == 'D')
		{
			game->map_dup = ft_db_free(game->map_dup);
			ft_error(ERR_DOOR, game, EXIT_FAILURE);
		}
		if (game->map_dup[y - 1][x] == ' ' || game->map_dup[y + 1][x] == ' ')
			ft_error(ERR_WALLS, game, EXIT_FAILURE);
		return (1);
	}
	return (0);
}
