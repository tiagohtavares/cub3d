/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:32:57 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/30 15:25:34 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/errors.h"
#include <math.h>
#include <stdio.h>

void	move_w(t_data *g)
{
	if (g->map[(int)(g->playery)][(int)(g->playerx + g->inidirx * 0.3)] != '1' && (g->map[(int)(g->playery)][(int)(g->playerx + g->inidirx * 0.3)] != 'D' || ft_get_door_state(g->door, (int)(g->playerx + g->inidirx * 0.5), (int)(g->playery), g->nbr_doors) != 1))
		g->playerx += g->inidirx * 0.1;
	if (g->map[(int)(g->playery + g->inidiry * 0.3)][(int)(g->playerx)] != '1' && (g->map[(int)(g->playery + g->inidiry * 0.3)][(int)(g->playerx)] != 'D' || ft_get_door_state(g->door, (int)(g->playerx), (int)(g->playery + g->inidiry * 0.3), g->nbr_doors) != 1))
		g->playery += g->inidiry * 0.1;
}

void	move_s(t_data *g)
{
	if (g->map[(int)(g->playery)][(int)(g->playerx - g->inidirx * 0.3)] != '1' && (g->map[(int)(g->playery)][(int)(g->playerx + g->inidirx * 0.3)] != 'D' || ft_get_door_state(g->door, (int)(g->playerx + g->inidirx * 0.3), (int)(g->playery), g->nbr_doors) != 1))
		g->playerx -= g->inidirx * 0.1;
	if (g->map[(int)(g->playery - g->inidiry * 0.3)][(int)(g->playerx)] != '1' && (g->map[(int)(g->playery + g->inidiry * 0.3)][(int)(g->playerx)] != 'D' || ft_get_door_state(g->door, (int)(g->playerx), (int)(g->playery + g->inidiry * 0.3), g->nbr_doors) != 1))
		g->playery -= g->inidiry * 0.1;
}

void	move_d(t_data *g)
{
	if (g->map[(int)(g->playery + g->inidirx * 0.3)][(int)(g->playerx)] != '1' && (g->map[(int)(g->playery)][(int)(g->playerx + g->inidirx * 0.3)] != 'D' || ft_get_door_state(g->door, (int)(g->playerx + g->inidirx * 0.3), (int)(g->playery), g->nbr_doors) != 1))
		g->playery += g->inidirx * 0.1;
	if (g->map[(int)(g->playery)][(int)(g->playerx - g->inidiry * 0.3)] != '1' && (g->map[(int)(g->playery)][(int)(g->playerx + g->inidirx * 0.3)] != 'D' || ft_get_door_state(g->door, (int)(g->playerx), (int)(g->playery + g->inidiry * 0.3), g->nbr_doors) != 1))
		g->playerx -= g->inidiry * 0.1;
}

void	move_a(t_data *g)
{
	if (g->map[(int)(g->playery - g->inidirx * 0.3)][(int)(g->playerx)] != '1' && (g->map[(int)(g->playery)][(int)(g->playerx + g->inidirx * 0.3)] != 'D' ||ft_get_door_state(g->door, (int)(g->playerx + g->inidirx * 0.3), (int)(g->playery), g->nbr_doors) != 1))
		g->playery -= g->inidirx * 0.1;
	if (g->map[(int)(g->playery)][(int)(g->playerx + g->inidiry * 0.3)] != '1' && (g->map[(int)(g->playery + g->inidiry * 0.3)][(int)(g->playerx)] != 'D' || ft_get_door_state(g->door, (int)(g->playerx), (int)(g->playery + g->inidiry * 0.3), g->nbr_doors) != 1))
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
