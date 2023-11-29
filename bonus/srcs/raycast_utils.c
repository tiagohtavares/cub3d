/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:38:58 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/29 12:37:36 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_side(t_data *g)
{
	if (g->side == 0)
	{
		g->wallx = g->playery + g->perpwalldistance * g->raydiry;
		g->wallx -= g->mapy;
	}
	else
	{
		g->wallx = g->playerx + g->perpwalldistance * g->raydirx;
		g->wallx -= g->mapx;
	}
}

void	ft_height(t_data *g, int *start, int *end)
{
	if (g->side == 0)
		g->perpwalldistance = (g->distancex - g->deltax);
	else
		g->perpwalldistance = (g->distancey - g->deltay);
	if (g->perpwalldistance == 0)
		g->lineh = W_HEIGHT;
	else
		g->lineh = (int)(W_HEIGHT / g->perpwalldistance);
	*start = -g->lineh / 2 + W_HEIGHT / 2;
	if (*start < 0)
		*start = 0;
	*end = g->lineh / 2 + W_HEIGHT / 2;
	if (*end >= W_HEIGHT)
		*end = W_HEIGHT - 1;
}

void	ft_hit(t_data *g)
{
	while (g->hit == 0)
	{
		if (g->distancex < g->distancey)
		{
			g->distancex += g->deltax;
			g->mapx += g->stepx;
			g->side = 0;
		}
		else
		{
			g->distancey += g->deltay;
			g->mapy += g->stepy;
			g->side = 1;
		}
		if (g->map[g->mapy][g->mapx] == '1' || g->map[g->mapy][g->mapx] == 'D')
			g->hit = 1;
	}
}
