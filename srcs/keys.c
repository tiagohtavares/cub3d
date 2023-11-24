/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:32:57 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/24 11:35:14 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/error.h"

void	move_w(t_data *g)
{
	if (g->map[(int)(g->playery)][(int)(g->playerx + g->inidirx * 0.3)] != '1')
		g->playerx += g->inidirx * 0.2;
	if (g->map[(int)(g->playery + g->inidiry * 0.3)][(int)(g->playerx)] != '1')
		g->playery += g->inidiry * 0.2;
	ft_raycast(g);
}

void	move_s(t_data *g)
{
	if (g->map[(int)(g->playery)][(int)(g->playerx - g->inidirx * 0.3)] != '1')
		g->playerx -= g->inidirx * 0.2;
	if (g->map[(int)(g->playery - g->inidiry * 0.3)][(int)(g->playerx)] != '1')
		g->playery -= g->inidiry * 0.2;
	ft_raycast(g);
}

void	move_d(t_data *g)
{
	if (g->map[(int)(g->playery + g->inidirx * 0.3)][(int)(g->playerx)] != '1')
		g->playery += g->inidirx * 0.2;
	if (g->map[(int)(g->playery)][(int)(g->playerx - g->inidiry * 0.3)] != '1')
		g->playerx -= g->inidiry * 0.2;
	ft_raycast(g);
}

void	move_a(t_data *g)
{
	if (g->map[(int)(g->playery - g->inidirx * 0.3)][(int)(g->playerx)] != '1')
		g->playery -= g->inidirx * 0.2;
	if (g->map[(int)(g->playery)][(int)(g->playerx + g->inidiry * 0.3)] != '1')
		g->playerx += g->inidiry * 0.2;
	ft_raycast(g);
}

int	keys(int key, t_data *g)
{
	if (key == XK_Escape)
		terminate_prog(g, EXIT_SUCCESS);
	else
		moves(key, g);
	return (0);
}
