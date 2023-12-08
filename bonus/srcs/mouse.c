/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:32:13 by heda-sil          #+#    #+#             */
/*   Updated: 2023/12/08 10:59:42 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate(double olddirx, double oldplanex, double ang, t_data *g)
{
	g->inidirx = g->inidirx * cos(ang) - g->inidiry * sin(ang);
	g->inidiry = olddirx * sin(ang) + g->inidiry * cos(ang);
	oldplanex = g->planex;
	g->planex = g->planex * cos(ang) - g->planey * sin(ang);
	g->planey = oldplanex * sin(ang) + g->planey * cos(ang);
}


int	mouse(int x, int y, t_data *g)
{
	int	dx;


	(void)y;
	dx = x - (W_WIDTH / 2);
	if (dx > -25 && dx < 25) // Creates a dead zone around crosshair
		return (0);
	if (dx > 0)
		rotate(g->inidirx, g->planex, 1 - pow(2, (double)dx/-40000), g);
	else if (dx < 0)
		rotate(g->inidirx, g->planex, 1 - pow(2, (double)dx/-40000), g);
	return (0);
}

int	mouse_pos(t_data *g)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(g->mlx, g->mlx_window, &x, &y);
	if (x <= W_WIDTH && y <= W_HEIGHT)
		mouse(x, y, g);
	return (0);
}
