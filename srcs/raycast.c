/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:10:54 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/24 11:39:52 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_direction(t_data *g)
{
	if (g->raydirx < 0)
	{
		g->stepx = -1;
		g->distancex = (g->playerx - g->mapx) * g->deltax;
	}
	else
	{
		g->stepx = 1;
		g->distancex = (g->mapx + 1.0 - g->playerx) * g->deltax;
	}
	if (g->raydiry < 0)
	{
		g->stepy = -1;
		g->distancey = (g->playery - g->mapy) * g->deltay;
	}
	else
	{
		g->stepy = 1;
		g->distancey = (g->mapy + 1.0 - g->playery) * g->deltay;
	}
}

void	ft_raycast_start(t_data *g, int x)
{
	g->camerax = 2 * x / (double)W_WIDTH - 1;
	g->raydirx = g->inidirx + g->planex * g->camerax;
	g->raydiry = g->inidiry + g->planey * g->camerax;
	g->mapx = (int)g->playerx;
	g->mapy = (int)g->playery;
	if (g->raydirx == 0)
		g->deltax = 1e30;
	else
		g->deltax = fabs(1 / g->raydirx);
	if (g->raydiry == 0)
		g->deltay = 1e30;
	else
		g->deltay = fabs(1 / g->raydiry);
	g->hit = 0;
	g->side = 0;
}

void	ft_raycast(t_data *g)
{
	int	start;
	int	end;
	int	x;

	x = 0;
	while (x < W_WIDTH)
	{
		ft_raycast_start(g, x);
		ft_direction(g);
		ft_hit(g);
		ft_height(g, &start, &end);
		ft_side(g);
		ft_texture_side(g);
		ft_texture_put(g, start, end, x);
		x++;
	}
	mlx_put_image_to_window(g->mlx, g->mlx_window, g->mlx_main, 0, 0);
}
