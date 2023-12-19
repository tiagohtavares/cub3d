/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:32:57 by ttavares          #+#    #+#             */
/*   Updated: 2023/12/19 02:03:19 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/errors.h"
#include <math.h>

void	move_w(t_data *g)
{
	int	x;
	int	y;

	x = (int)(g->playerx + g->inidirx * PLAYER_ZOOM);
	y = (int)(g->playery + g->inidiry * PLAYER_ZOOM);
	if (g->map[y][x] != '1' && (g->map[y][x] != 'D' || \
	ft_get_door_state(g->door, x, y, g->nbr_doors) != 1))
	{
		g->playerx += g->inidirx * PLAYER_SPEED;
		g->playery += g->inidiry * PLAYER_SPEED;
	}
	x = (int)(g->playerx - 4 * (g->inidirx * PLAYER_ZOOM));
	y = (int)(g->playery - 4 * (g->inidiry * PLAYER_ZOOM));
	if (g->map[y][x] == 'D' && !ft_get_door_state(g->door, x, y, g->nbr_doors))
		ft_set_door_state(g, x, y, 1);
}

void	move_s(t_data *g)
{
	int	x;
	int	y;

	x = (int)(g->playerx - g->inidirx * PLAYER_ZOOM);
	y = (int)(g->playery - g->inidiry * PLAYER_ZOOM);
	if (g->map[y][x] != '1' && (g->map[y][x] != 'D' || \
	ft_get_door_state(g->door, x, y, g->nbr_doors) != 1))
	{
		g->playerx -= g->inidirx * PLAYER_SPEED;
		g->playery -= g->inidiry * PLAYER_SPEED;
	}
	x = (int)(g->playerx + 4 * (g->inidirx * PLAYER_ZOOM));
	y = (int)(g->playery + 4 * (g->inidiry * PLAYER_ZOOM));
	if (g->map[y][x] == 'D' && !ft_get_door_state(g->door, x, y, g->nbr_doors))
		ft_set_door_state(g, x, y, 1);
}

void	move_d(t_data *g)
{
	int	x;
	int	y;

	x = (int)(g->playerx - g->inidiry * PLAYER_ZOOM);
	y = (int)(g->playery + g->inidirx * PLAYER_ZOOM);
	if (g->map[y][x] != '1' && (g->map[y][x] != 'D' || \
	ft_get_door_state(g->door, x, y, g->nbr_doors) != 1))
	{
		g->playery += g->inidirx * PLAYER_SPEED;
		g->playerx -= g->inidiry * PLAYER_SPEED;
	}
	x = (int)(g->playerx + 4 * (g->inidiry * PLAYER_ZOOM));
	y = (int)(g->playery - 4 * (g->inidirx * PLAYER_ZOOM));
	if (g->map[y][x] == 'D' && !ft_get_door_state(g->door, x, y, g->nbr_doors))
		ft_set_door_state(g, x, y, 1);
}

void	move_a(t_data *g)
{
	int	x;
	int	y;

	x = (int)(g->playerx + g->inidiry * PLAYER_ZOOM);
	y = (int)(g->playery - g->inidirx * PLAYER_ZOOM);
	if (g->map[y][x] != '1' && (g->map[y][x] != 'D' || \
	ft_get_door_state(g->door, x, y, g->nbr_doors) != 1))
	{
		g->playery -= g->inidirx * PLAYER_SPEED;
		g->playerx += g->inidiry * PLAYER_SPEED;
	}
	x = (int)(g->playerx - 4 * (g->inidiry * PLAYER_ZOOM));
	y = (int)(g->playery + 4 * (g->inidirx * PLAYER_ZOOM));
	if (g->map[y][x] == 'D' && !ft_get_door_state(g->door, x, y, g->nbr_doors))
		ft_set_door_state(g, x, y, 1);
}

int	keys(int key, t_data *g)
{
	if (key == XK_Escape)
		terminate_prog(g, EXIT_SUCCESS);
	else if (key == XK_space)
		open_door(g);
	else
		moves(key, g);
	return (0);
}
