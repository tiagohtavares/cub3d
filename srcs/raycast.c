/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by ttavares          #+#    #+#             */
/*   Updated: 2023/11/02 17:07:08 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_raycast_horizontal(t_data *gameinfo)
{
	int	dof;
	double	aTan;

	dof = 0;
	gameinfo->raya = gameinfo->playera;
	aTan = -1 / tan(gameinfo->raya);
	if (gameinfo->raya < PI) // North
	{
		gameinfo->rayy = (int)((gameinfo->playery / 64) * 64) - 0.0001;
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
	if (gameinfo->raya == 0 || gameinfo->raya == PI)
	{
		gameinfo->rayx = gameinfo->playerx;
		gameinfo->rayy = gameinfo->playery;
		dof = 8;
	}
	//ft_line(gameinfo, gameinfo->playerx, gameinfo->playery, gameinfo->rayx, gameinfo->rayy);
	while (dof < 8)
	{
		gameinfo->mapx = (int) gameinfo->rayx / 64;
		gameinfo->mapy = (int) gameinfo->rayy / 64;
		printf("Rayx: %d\t|\tRayy: %d\n", gameinfo->rayx, gameinfo->rayy);
		printf("Raygridx: %d\t|\tRaygridy: %d\n", gameinfo->mapx, gameinfo->mapy);
		if (gameinfo->mapx > gameinfo->map_sizex - 1 || gameinfo->mapy > gameinfo->map_sizey - 1)
			break;
		if (gameinfo->mapx < 0 || gameinfo->mapy < 0)
			break;
		gameinfo->mapp = gameinfo->mapy * gameinfo->map_sizex + gameinfo->mapx;
		if (gameinfo->mapp < gameinfo->map_sizex * gameinfo->map_sizey && gameinfo->map[gameinfo->mapy][gameinfo->mapx] == '1')
		{
			gameinfo->distanceH = ft_distance(gameinfo->playerx, gameinfo->playery, gameinfo->rayx, gameinfo->rayy);
			gameinfo->rayxH = gameinfo->rayx;
			gameinfo->rayyH = gameinfo->rayy;
			dof = 8;
		}
		else
		{
			gameinfo->rayx -= gameinfo->rayofssetx;
			gameinfo->rayy -= gameinfo->rayofssety;
			dof += 1;
		}
	}
}

void	ft_raycast_vertical(t_data *gameinfo)
{
	int	dof;
	double	aTan;

	dof = 0;
	gameinfo->raya = gameinfo->playera;
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
	if (gameinfo->raya == 0 || gameinfo->raya == PI)
	{
		gameinfo->rayx = gameinfo->playerx;
		gameinfo->rayy = gameinfo->playery;
		dof = 8;
	}
	(void)dof;
	//ft_line(gameinfo, gameinfo->playerx, gameinfo->playery, gameinfo->rayx, gameinfo->rayy, 255);
	while (dof < 8)
	{
		gameinfo->mapx = (int) gameinfo->rayx / 64;
		gameinfo->mapy = (int) gameinfo->rayy / 64;
		printf("Rayx: %d\t|\tRayy: %d\n", gameinfo->rayx, gameinfo->rayy);
		printf("Raygridx: %d\t|\tRaygridy: %d\n", gameinfo->mapx, gameinfo->mapy);
		if (gameinfo->mapx > gameinfo->map_sizex - 1 || gameinfo->mapy > gameinfo->map_sizey - 1)
			break;
		if (gameinfo->mapx < 0 || gameinfo->mapy < 0)
			break;
		gameinfo->mapp = gameinfo->mapy * gameinfo->map_sizex + gameinfo->mapx;
		if (gameinfo->mapp < gameinfo->map_sizex * gameinfo->map_sizey && gameinfo->map[gameinfo->mapy][gameinfo->mapx] == '1')
		{
			gameinfo->distanceV = ft_distance(gameinfo->playerx, gameinfo->playery, gameinfo->rayx, gameinfo->rayy);
			gameinfo->rayxV = gameinfo->rayx;
			gameinfo->rayyV = gameinfo->rayy;
			dof = 8;
		}
		else
		{
			gameinfo->rayx += gameinfo->rayofssetx;
			gameinfo->rayy += gameinfo->rayofssety;
			dof += 1;
		}
	}

}
