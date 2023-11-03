/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by ttavares          #+#    #+#             */
/*   Updated: 2023/11/03 07:51:17 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_raycast(t_data *gameinfo) // Raycast Loop
{
	int	r;

	r = -30;

	// printf("Mapx %d, Mapy %d", gameinfo->map_sizex, gameinfo->map_sizey);
	// printf("Player Angle %f\n",gameinfo->playera);
	// printf("Playerx %d	Playery %d\n",gameinfo->playerx, gameinfo->playery);
	gameinfo->raya = gameinfo->playera;
	gameinfo->raya -= 30 * ONED;
	while (r < 30)
	{
		ft_raycast_horizontal(gameinfo);
		//ft_line(gameinfo, gameinfo->playerx, gameinfo->playery, gameinfo->rayx, gameinfo->rayy);
		ft_raycast_vertical(gameinfo);
		//ft_line(gameinfo, gameinfo->playerx, gameinfo->playery, gameinfo->rayx, gameinfo->rayy);
		if (gameinfo->distanceH >= gameinfo->distanceV)
		{
			ft_line(gameinfo, gameinfo->playerx, gameinfo->playery, gameinfo->rayxV, gameinfo->rayyV);
			gameinfo->finaldistance = gameinfo->distanceV;
			gameinfo->rayfinala = gameinfo->rayaV;
		}
		else if (gameinfo->distanceV > gameinfo->distanceH)
		{
			ft_line(gameinfo, gameinfo->playerx, gameinfo->playery, gameinfo->rayxH, gameinfo->rayyH);
			gameinfo->finaldistance = gameinfo->distanceH;
			gameinfo->rayfinala = gameinfo->rayaH;
		}
		gameinfo->raya += ONED;
		ft_draw3d(gameinfo, r);
		r++;
	}
}

void	ft_raycast_horizontal(t_data *gameinfo) //Check colisions horizontal line
{
	int	dof;
	double	aTan;

	dof = 0;
	aTan = -1 / tan(gameinfo->raya);
	if (gameinfo->raya < PI) // North
	{
		gameinfo->rayy = (int)((gameinfo->playery / 64) * 64) - 0.001;
		gameinfo->rayx = (gameinfo->playery - gameinfo->rayy) * aTan + gameinfo->playerx;
		gameinfo->rayofssety = 64;
		gameinfo->rayofssetx = -gameinfo->rayofssety * aTan;
	}
	if (gameinfo->raya > PI) // South
	{
		gameinfo->rayy = (int)((gameinfo->playery / 64) * 64) + 64;
		gameinfo->rayx = (gameinfo->playery - gameinfo->rayy) * aTan + gameinfo->playerx;
		gameinfo->rayofssety = -64;
		gameinfo->rayofssetx = -gameinfo->rayofssety * aTan;
	}
	if (gameinfo->raya == 0)
	{
		gameinfo->rayx = gameinfo->playerx;
		gameinfo->rayy = gameinfo->playery;
		gameinfo->rayofssetx = 64;
		gameinfo->rayofssetx = 0;
	}
	if (gameinfo->raya == PI)
	{
		gameinfo->rayx = gameinfo->playerx;
		gameinfo->rayy = gameinfo->playery;
		gameinfo->rayofssetx = -64;
		gameinfo->rayofssetx = 0;
	}
	while (dof < 12)
	{
		// printf("Entered dof cycle horizontal\n");
		gameinfo->mapx = (int) gameinfo->rayx / 64;
		gameinfo->mapy = (int) gameinfo->rayy / 64;
		if (gameinfo->mapx > gameinfo->map_sizex - 1 || gameinfo->mapy > gameinfo->map_sizey - 1)
		{
			gameinfo->distanceH = 10000;
			break;
		}
		if (gameinfo->mapx < 0 || gameinfo->mapy < 0)
		{
			gameinfo->distanceH = 10000;
			break;
		}
		if (gameinfo->map[gameinfo->mapy][gameinfo->mapx] == '1')
		{
			// printf("Finshed horizontal in %d dof\n", dof);
			gameinfo->distanceH = ft_distance(gameinfo->playerx, gameinfo->playery, gameinfo->rayx, gameinfo->rayy);
			gameinfo->rayxH = gameinfo->rayx;
			gameinfo->rayyH = gameinfo->rayy;
			gameinfo->rayaH = gameinfo->raya;
			dof = 12;
		}
		else
		{
			gameinfo->rayx -= gameinfo->rayofssetx;
			gameinfo->rayy -= gameinfo->rayofssety;
			dof += 1;
		}
	}
	// ft_draw_player(gameinfo, gameinfo->rayx, gameinfo->rayy, 0, 16);
	// printf("Horizontal Rayx %d	Rayy %d\n",gameinfo->rayx, gameinfo->rayy);
	// printf("Horizontal RayMapx %d	RayMapy %d\n",gameinfo->mapx, gameinfo->mapy);
	// printf("Horizontal Mapp %d\n",gameinfo->mapp);
	// printf("Horizontal Distance %f\n",gameinfo->distanceH);
}

void	ft_raycast_vertical(t_data *gameinfo) //Check colisions vertical line
{
	int	dof;
	double	aTan;

	dof = 0;
	aTan = -tan(gameinfo->raya);
	if (gameinfo->raya > PI / 2 && gameinfo->raya < 3 * PI / 2) // West
	{
		gameinfo->rayx = (int)((gameinfo->playerx / 64) * 64) + 64;
		gameinfo->rayy = (gameinfo->playerx - gameinfo->rayx) * aTan + gameinfo->playery;
		gameinfo->rayofssetx = 64;
		gameinfo->rayofssety = -gameinfo->rayofssetx * aTan;
	}
	if (gameinfo->raya < PI /2 || gameinfo->raya > 3 * PI / 2 ) // East
	{
		gameinfo->rayx = (int)((gameinfo->playerx / 64) * 64) -.001;
		gameinfo->rayy = (gameinfo->playerx - gameinfo->rayx) * aTan + gameinfo->playery;
		gameinfo->rayofssetx = -64;
		gameinfo->rayofssety = -gameinfo->rayofssetx * aTan;
	}
	if (gameinfo->raya == PI/2)
	{
		gameinfo->rayx = gameinfo->playerx;
		gameinfo->rayy = gameinfo->playery;
		gameinfo->rayofssetx = 0;
		gameinfo->rayofssety = -64;
	}
	if	(gameinfo->raya == 3*PI/2)
	{
		gameinfo->rayx = gameinfo->playerx;
		gameinfo->rayy = gameinfo->playery;
		gameinfo->rayofssetx = 0;
		gameinfo->rayofssety = 64;
	}
	while (dof < 12)
	{
		// printf("Entered dof cycle vertical \n");
		gameinfo->mapx = (int) gameinfo->rayx / 64;
		gameinfo->mapy = (int) gameinfo->rayy / 64;
		if (gameinfo->mapx > gameinfo->map_sizex - 1 || gameinfo->mapy > gameinfo->map_sizey - 1)
		{
			gameinfo->distanceV = 100000;
			break;
		}
		if (gameinfo->mapx < 0 || gameinfo->mapy < 0)
		{
			gameinfo->distanceV = 100000;
			break;
		}
		if (gameinfo->map[gameinfo->mapy][gameinfo->mapx] == '1')
		{
			// printf("Finshed vertical in %d dof\n", dof);
			gameinfo->distanceV = ft_distance(gameinfo->playerx, gameinfo->playery, gameinfo->rayx, gameinfo->rayy);
			gameinfo->rayxV = gameinfo->rayx;
			gameinfo->rayyV = gameinfo->rayy;
			gameinfo->rayaV = gameinfo->raya;
			dof = 12;
		}
		else
		{
			gameinfo->rayx += gameinfo->rayofssetx;
			gameinfo->rayy += gameinfo->rayofssety;
			dof += 1;
		}
	}
	// ft_draw_player(gameinfo, gameinfo->rayx, gameinfo->rayy, 255, 16);
	// printf("Vertical	Rayx %d	Rayy %d\n",gameinfo->rayx, gameinfo->rayy);
	// printf("Vertical	RayMapx %d	RayMapy %d\n",gameinfo->mapx, gameinfo->mapy);
	// printf("Vertical Mapp %d\n",gameinfo->mapp);
	// printf("Vertical Distance %f\n",gameinfo->distanceV);
}
