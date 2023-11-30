/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:33:53 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/30 15:26:53 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/errors.h"

void	moves(int key, t_data *g)
{
	if (key == XK_w)
		move_w(g);
	else if (key == XK_s)
		move_s(g);
	else if (key == XK_a)
		move_a(g);
	else if (key == XK_d)
		move_d(g);
	else if (key == XK_Right)
		move_right(g);
	else if (key == XK_Left)
		move_left(g);
}

void	move_left(t_data *g)
{
	double	olddirx;
	double	oldplanex;

	olddirx = g->inidirx;
	g->inidirx = g->inidirx * cos(-0.1) - g->inidiry * sin(-0.1);
	g->inidiry = olddirx * sin(-0.1) + g->inidiry * cos(-0.1);
	oldplanex = g->planex;
	g->planex = g->planex * cos(-0.1) - g->planey * sin(-0.1);
	g->planey = oldplanex * sin(-0.1) + g->planey * cos(-0.1);
}

void	move_right(t_data *g)
{
	double	olddirx;
	double	oldplanex;

	olddirx = g->inidirx;
	g->inidirx = g->inidirx * cos(0.1) - g->inidiry * sin(0.1);
	g->inidiry = olddirx * sin(0.1) + g->inidiry * cos(0.1);
	oldplanex = g->planex;
	g->planex = g->planex * cos(0.1) - g->planey * sin(0.1);
	g->planey = oldplanex * sin(0.1) + g->planey * cos(0.1);
}

int	x_button(t_data *g)
{
	terminate_prog(g, EXIT_SUCCESS);
	return (0);
}

void	open_door(t_data *g)
{
	int	i;

	i = 0;
	while (i < g->nbr_doors)
	{
		if (g->door[i].x == (int)(g->playerx + g->inidirx * 0.3) && \
		g->door[i].y == (int)(g->playery + g->inidiry * 0.3))
			g->door[i].state = 0;
		i++;
	}
	// wait and then close door
}
