/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:29:57 by heda-sil          #+#    #+#             */
/*   Updated: 2023/12/08 11:51:09 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/errors.h"

int	check_door_vertical(t_data *gameinfo, int x, int y)
{
	if (gameinfo->map_dup[y - 1][x] == '1' && gameinfo->map_dup[y + 1][x] == '1')
	{
		if (gameinfo->map_dup[y][x - 1] == '1' || \
		gameinfo->map_dup[y][x + 1] == '1' || \
		gameinfo->map_dup[y][x - 1] == 'D' || \
		gameinfo->map_dup[y][x + 1] == 'D')
		{
			gameinfo->map_dup = ft_db_free(gameinfo->map_dup);
			ft_error(ERR_DOOR, gameinfo, EXIT_FAILURE);
		}
		if (gameinfo->map_dup[y][x - 1] == ' ' || gameinfo->map_dup[y][x + 1] == ' ')
			ft_error(ERR_WALLS, gameinfo, EXIT_FAILURE);
		return (1);
	}
	return (0);
}

int	check_door_horizontal(t_data *gameinfo, int x, int y)
{
	if (gameinfo->map_dup[y][x - 1] == '1' && gameinfo->map_dup[y][x + 1] == '1')
	{
		if (gameinfo->map_dup[y - 1][x] == '1' || \
		gameinfo->map_dup[y + 1][x] == '1' || \
		gameinfo->map_dup[y - 1][x] == 'D' || \
		gameinfo->map_dup[y + 1][x] == 'D')
		{
			gameinfo->map_dup = ft_db_free(gameinfo->map_dup);
			ft_error(ERR_DOOR, gameinfo, EXIT_FAILURE);
		}
		if (gameinfo->map_dup[y- 1][x] == ' ' || gameinfo->map_dup[y + 1][x] == ' ')
			ft_error(ERR_WALLS, gameinfo, EXIT_FAILURE);
		return (1);
	}
	return (0);
}
