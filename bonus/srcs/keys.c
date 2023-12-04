/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:32:57 by ttavares          #+#    #+#             */
/*   Updated: 2023/12/04 13:35:22 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/errors.h"
#include <math.h>
#include <stdio.h>

void	move_w(t_data *g)
{
	int	x;
	int	y;

	x = (int)(g->playerx + g->inidirx * 0.5);
	y = (int)(g->playery);
	if (g->map[y][x] != '1' && (g->map[y][x] != 'D' || \
	ft_get_door_state(g->door, x, y, g->nbr_doors) != 1))
		g->playerx += g->inidirx * 0.1;
	x = (int)(g->playerx);
	y = (int)(g->playery + g->inidiry * 0.5);
	if (g->map[y][x] != '1' && (g->map[y][x] != 'D' || \
	ft_get_door_state(g->door, x, y, g->nbr_doors) != 1))
		g->playery += g->inidiry * 0.1;
}

void	move_s(t_data *g)
{
	int	x;
	int	y;

	x = (int)(g->playerx - g->inidirx * 0.5);
	y = (int)(g->playery);
	if (g->map[y][x] != '1' && (g->map[y][x] != 'D' || \
	ft_get_door_state(g->door, x, y, g->nbr_doors) != 1))
		g->playerx -= g->inidirx * 0.1;
	x = (int)(g->playerx);
	y = (int)(g->playery - g->inidiry * 0.5);
	if (g->map[y][x] != '1' && (g->map[y][x] != 'D' || \
	ft_get_door_state(g->door, x, y, g->nbr_doors) != 1))
		g->playery -= g->inidiry * 0.1;
}

void	move_d(t_data *g)
{
	int	x;
	int	y;

	x = (int)(g->playerx);
	y = (int)(g->playery + g->inidirx * 0.5);
	if (g->map[y][x] != '1' && (g->map[y][x] != 'D' || \
	ft_get_door_state(g->door, x, y, g->nbr_doors) != 1))
		g->playery += g->inidirx * 0.1;
	x = (int)(g->playerx - g->inidiry * 0.5);
	y = (int)(g->playery);
	if (g->map[y][x] != '1' && (g->map[y][x] != 'D' || \
	ft_get_door_state(g->door, x, y, g->nbr_doors) != 1))
		g->playerx -= g->inidiry * 0.1;
}

void	move_a(t_data *g)
{
	int	x;
	int	y;

	x = (int)(g->playerx);
	y = (int)(g->playery - g->inidirx * 0.5);
	if (g->map[y][x] != '1' && (g->map[y][x] != 'D' || \
	ft_get_door_state(g->door, x, y, g->nbr_doors) != 1))
		g->playery -= g->inidirx * 0.1;
	x = (int)(g->playerx + g->inidiry * 0.5);
	y = (int)(g->playery);
	if (g->map[y][x] != '1' && (g->map[y][x] != 'D' || \
	ft_get_door_state(g->door, x, y, g->nbr_doors) != 1))
		g->playerx += g->inidiry * 0.1;
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
