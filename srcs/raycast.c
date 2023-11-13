/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:10:54 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/13 15:40:19 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_raycast(t_data *gameinfo)
{
	double	start;
	double	end;
	int	x;

	x = 0;
	while(x < W_WIDTH)
	{
		gameinfo->camerax = 2 * x / (double)W_WIDTH - 1;
		gameinfo->raydirx = gameinfo->inidirx + gameinfo->planex * gameinfo->camerax;
		gameinfo->raydiry = gameinfo->inidiry + gameinfo->planey * gameinfo->camerax;
		gameinfo->mapx = (int)gameinfo->playerx;
		gameinfo->mapy = (int)gameinfo->playery;
		if(gameinfo->raydirx == 0)
			gameinfo->deltax = 1e30;
		else
			gameinfo->deltax = fabs(1 / gameinfo->raydirx);
		if(gameinfo->raydiry == 0)
			gameinfo->deltay = 1e30;
		else
			gameinfo->deltay = fabs(1 / gameinfo->raydiry);
		gameinfo->hit = 0;
		gameinfo->side = 0;
		if(gameinfo->raydirx < 0)
		{
			gameinfo->stepx = -1;
			gameinfo->distancex = (gameinfo->playerx - gameinfo->mapx) * gameinfo->deltax;
		}
		else
		{
			gameinfo->stepx = 1;
			gameinfo->distancex = (gameinfo->mapx + 1.0 - gameinfo->playerx) * gameinfo->deltax;
		}
		if(gameinfo->raydiry < 0)
		{
			gameinfo->stepy = -1;
			gameinfo->distancey = (gameinfo->playery - gameinfo->mapy) * gameinfo->deltay;
		}
		else
		{
			gameinfo->stepy = 1;
			gameinfo->distancey = (gameinfo->mapy + 1.0 - gameinfo->playery) * gameinfo->deltay;
		}
		while(gameinfo->hit == 0)
		{
			if(gameinfo->distancex < gameinfo->distancey)
			{
				gameinfo->distancex += gameinfo->deltax;
				gameinfo->mapx += gameinfo->stepx;
				gameinfo->side = 0;
			}
			else
			{
				gameinfo->distancey += gameinfo->deltay;
				gameinfo->mapy += gameinfo->stepy;
				gameinfo->side = 1;
			}
			if(gameinfo->mapy < 0)
				gameinfo->mapy = 0;
			if(gameinfo->mapx < 0)
				gameinfo->mapx = 0;
			if(gameinfo->map[gameinfo->mapy][gameinfo->mapx] == '1')
				gameinfo->hit = 1;
		}
		if (gameinfo->side == 0)
			gameinfo->perpwalldistance = (gameinfo->distancex - gameinfo->deltax);
		else
			gameinfo->perpwalldistance = (gameinfo->distancey - gameinfo->deltay);
		if(gameinfo->perpwalldistance == 0)
			gameinfo->lineh = W_HEIGHT;
		else
			gameinfo->lineh = (int)(W_HEIGHT / gameinfo->perpwalldistance);
		start = -gameinfo->lineh / 2 + W_HEIGHT / 2;
		if(start < 0)
			start = 0;
		end = gameinfo->lineh / 2 + W_HEIGHT /2;
		if(end >= W_HEIGHT)
			end = W_HEIGHT - 1;
		if (gameinfo->side == 1)
			gameinfo->color = C_RED;
		if (gameinfo->side == 0)
			gameinfo->color = C_BLUE;
		ft_draw_vertical(gameinfo, x, (int)start, (int)end, gameinfo->color);
		x++;
	}
}
