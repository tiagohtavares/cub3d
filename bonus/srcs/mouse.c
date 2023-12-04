/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:32:13 by heda-sil          #+#    #+#             */
/*   Updated: 2023/12/04 16:38:01 by heda-sil         ###   ########.fr       */
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


// TODO: Change so that view drifts to follow the mouse position even if mouse is not moving
int	mouse(int x, int y, t_data *g)
{
	int	dx;

	// REMOVE: old way to move base on when mouse is moved inside the game
	// if (x < W_WIDTH / 6)
	// 	mlx_mouse_move(g->mlx, g->mlx_window, W_WIDTH / 2, W_HEIGHT / 2);
	// else if (x > (5 * W_WIDTH) / 6)
	// 	mlx_mouse_move(g->mlx, g->mlx_window, W_WIDTH / 2, W_HEIGHT / 2);
	// if (y < W_HEIGHT / 4 || y > (3 * W_HEIGHT) / 4)
	// 	mlx_mouse_move(g->mlx, g->mlx_window, x, W_HEIGHT / 2);
	// dx = x - g->old_x;
	// if (dx == 0)
	// {
	// 	dx = x - (W_WIDTH / 2);
	// 	if (dx > -50 && dx < 50) // Creates a dead zone around crosshair
	// 		return (0);
	// }
	printf("x: %d\n", x);
	printf("old: %d\n", g->old_x);
	g->old_x = x;
	(void)y;
	// TMP: New way is based on difference between mouse pos and middle screen it creates a drift i need to make the value of rotation to be exponential and smoother
	dx = x - (W_WIDTH / 2);
	if (dx > -50 && dx < 50) // Creates a dead zone around crosshair
		return (0);
	printf("Dx: %d\n", dx); // REMOVE
	printf("Dx: %f\n", 1 - pow(2, (double)dx/-10000)); //REMOVE
	if (dx > 0)
		rotate(g->inidirx, g->planex, 0.01, g);
	else if (dx < 0)
		rotate(g->inidirx, g->planex, -0.01, g);
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
