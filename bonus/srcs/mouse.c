/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:32:13 by heda-sil          #+#    #+#             */
/*   Updated: 2023/11/29 17:21:34 by heda-sil         ###   ########.fr       */
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

// TODO: Need to improve view moviment, some performance trouble, only works if mouse is moving
int	mouse(int x, int y, t_data *g)
{
	int		dx;

	// mlx_mouse_hide(g->mlx, g->mlx_window); // TMP: Moved to main
	if (x < W_WIDTH / 4)
		mlx_mouse_move(g->mlx, g->mlx_window, x + W_WIDTH / 4, y);
	if (x > (3 * W_WIDTH) / 4)
		mlx_mouse_move(g->mlx, g->mlx_window, x - W_WIDTH / 4, y);
	dx = g->old_x - x;
	g->old_x = x;
	if (dx > 0)
	{
		ft_mouse_rotate(g->inidirx, g->planex, -0.05, g);
	}
	else
	{
		ft_mouse_rotate(g->inidirx, g->planex, 0.05, g);
	}
	ft_raycast(g);
	return (0);
}
