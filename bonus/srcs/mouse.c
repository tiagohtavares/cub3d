/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:32:13 by heda-sil          #+#    #+#             */
/*   Updated: 2023/11/30 12:30:13 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_mouse_rotate(double olddirx, double oldplanex, double ang, t_data *g)
{
	g->inidirx = g->inidirx * cos(ang) - g->inidiry * sin(ang);
	g->inidiry = olddirx * sin(ang) + g->inidiry * cos(ang);
	oldplanex = g->planex;
	g->planex = g->planex * cos(ang) - g->planey * sin(ang);
	g->planey = oldplanex * sin(ang) + g->planey * cos(ang);
}

int	mouse(int x, int y, t_data *g)
{
	int		dx;

	if (x < W_WIDTH / 6)
		mlx_mouse_move(g->mlx, g->mlx_window, x + W_WIDTH / 6, W_HEIGHT / 2);
	if (x > (5 * W_WIDTH) / 6)
		mlx_mouse_move(g->mlx, g->mlx_window, x - W_WIDTH / 6, W_HEIGHT / 2);
	if (y < W_HEIGHT / 4 || y > (3 * W_HEIGHT) / 4)
		mlx_mouse_move(g->mlx, g->mlx_window, x, W_HEIGHT / 2);
	dx = g->old_x - x;
	g->old_x = x;
	if (dx > 0)
	{
		ft_mouse_rotate(g->inidirx, g->planex, -0.03, g);
	}
	else
	{
		ft_mouse_rotate(g->inidirx, g->planex, 0.03, g);
	}
	return (0);
}
