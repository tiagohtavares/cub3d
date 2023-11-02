/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys->c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:14:44 by ttavares          #+#    #+#             */
/*   Updated: 2023/10/30 16:59:45 by ttavares         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/error.h"
#include <math.h>
#include <stdio.h>

void	move_w(t_data *gameinfo)
{
	gameinfo->playerx -= gameinfo->playerdx;
	gameinfo->playery -= gameinfo->playerdy;
	gameinfo->player_gridx = gameinfo->playerx / WIDTH;
	gameinfo->player_gridy = gameinfo->playery / HEIGHT;
	/* if (gameinfo->playerx % WIDTH == 0)
	{
		gameinfo->player_gridx--;
	}
	if (gameinfo->playery % HEIGHT == 0)
	{
		gameinfo->player_gridy--;

	} */
	printf("Playerx: %d\t|\tPlayery: %d\n", gameinfo->playerx, gameinfo->playery);
	printf("PlayerGridx: %d\t|\tPlayerGridy: %d\n", gameinfo->player_gridx, gameinfo->player_gridy);
	printf("Playera: %f\t|\tRaya: %f\n", gameinfo->playera, gameinfo->raya);
	printf("Rayx: %d\t|\tRayy: %d\n", gameinfo->rayx, gameinfo->rayy);
	printf("Raygridx: %d\t|\tRaygridy: %d\n", gameinfo->mapx, gameinfo->mapy);
	//ft_check_collisions(gameinfo->map, gameinfo->player_gridx, gameinfo->player_gridy, gameinfo);
	ft_clear(gameinfo);
	ft_raycast_horizontal(gameinfo);
	ft_raycast_vertical(gameinfo);
	ft_draw_minimap(gameinfo);
	ft_draw_player(gameinfo, gameinfo->playerx, gameinfo->playery, 10197915, 24);
	printf("DistanceH :%f  DistanceV: %f", gameinfo->distanceH, gameinfo->distanceV);
	if (gameinfo->distanceH < gameinfo->distanceV)
	{
		ft_line(gameinfo, gameinfo->playerx, gameinfo->playery, gameinfo->rayxH, gameinfo->rayyH, 65280);
		ft_draw3d(gameinfo, gameinfo->distanceH);
	}
	else if (gameinfo->distanceH > gameinfo->distanceV)
	{
		ft_line(gameinfo, gameinfo->playerx, gameinfo->playery, gameinfo->rayxV, gameinfo->rayyV, 65280);
		ft_draw3d(gameinfo, gameinfo->distanceV);
	}
}

void	move_s(t_data *gameinfo)
{
	gameinfo->playerx += gameinfo->playerdx;
	gameinfo->playery += gameinfo->playerdy;
	gameinfo->player_gridx = gameinfo->playerx / WIDTH;
	gameinfo->player_gridy = gameinfo->playery / HEIGHT;
	/* if (gameinfo->playerx % WIDTH == 0)
	{
		gameinfo->player_gridx++;
	}
	if (gameinfo->playery % HEIGHT == 0)
	{
		gameinfo->player_gridy++;

	} */
	printf("Playerx: %d\t|\tPlayery: %d\n", gameinfo->playerx, gameinfo->playery);
	printf("PlayerGridx: %d\t|\tPlayerGridy: %d\n", gameinfo->player_gridx, gameinfo->player_gridy);
	printf("Playera: %f\t|\tRaya: %f\n", gameinfo->playera, gameinfo->raya);
	printf("Rayx: %d\t|\tRayy: %d\n", gameinfo->rayx, gameinfo->rayy);
	printf("Raygridx: %d\t|\tRaygridy: %d\n", gameinfo->mapx, gameinfo->mapy);
	//ft_check_collisions(gameinfo->map, gameinfo->playerx, gameinfo->playery, gameinfo);
	ft_clear(gameinfo);
	ft_raycast_horizontal(gameinfo);
	ft_raycast_vertical(gameinfo);
	ft_draw_minimap(gameinfo);
	ft_draw_player(gameinfo, gameinfo->playerx, gameinfo->playery, 10197915, 24);
	printf("DistanceH :%f  DistanceV: %f", gameinfo->distanceH, gameinfo->distanceV);
	if (gameinfo->distanceH < gameinfo->distanceV)
	{
		ft_line(gameinfo, gameinfo->playerx, gameinfo->playery, gameinfo->rayxH, gameinfo->rayyH, 65280);
		ft_draw3d(gameinfo, gameinfo->distanceH);
	}
	else if (gameinfo->distanceH > gameinfo->distanceV)
	{
		ft_line(gameinfo, gameinfo->playerx, gameinfo->playery, gameinfo->rayxV, gameinfo->rayyV, 65280);
		ft_draw3d(gameinfo, gameinfo->distanceV);
	}
}

void	move_a(t_data *gameinfo)
{
	gameinfo->playera -= 0.02;
	if (gameinfo->playera < 0)
		gameinfo->playera += PI*2;
	gameinfo->playerdx = (int)((cos(gameinfo->playera) * 5));
	gameinfo->playerdy = (int)((sin(gameinfo->playera) * 5));
	printf("Playerx: %d\t|\tPlayery: %d\n", gameinfo->playerx, gameinfo->playery);
	printf("PlayerGridx: %d\t|\tPlayerGridy: %d\n", gameinfo->player_gridx, gameinfo->player_gridy);
	printf("Playera: %f\t|\tRaya: %f\n", gameinfo->playera, gameinfo->raya);
	printf("Rayx: %d\t|\tRayy: %d\n", gameinfo->rayx, gameinfo->rayy);
	printf("Raygridx: %d\t|\tRaygridy: %d\n", gameinfo->mapx, gameinfo->mapy);
	ft_clear(gameinfo);
	ft_raycast_horizontal(gameinfo);
	ft_raycast_vertical(gameinfo);
	ft_draw_minimap(gameinfo);
	ft_draw_player(gameinfo, gameinfo->playerx, gameinfo->playery, 10197915, 24);
	printf("DistanceH :%f  DistanceV: %f", gameinfo->distanceH, gameinfo->distanceV);
	if (gameinfo->distanceH < gameinfo->distanceV)
	{
		ft_line(gameinfo, gameinfo->playerx, gameinfo->playery, gameinfo->rayxH, gameinfo->rayyH, 65280);
		ft_draw3d(gameinfo, gameinfo->distanceH);
	}
	else if (gameinfo->distanceH > gameinfo->distanceV)
	{
		ft_line(gameinfo, gameinfo->playerx, gameinfo->playery, gameinfo->rayxV, gameinfo->rayyV, 65280);
		ft_draw3d(gameinfo, gameinfo->distanceV);
	}
}

void	move_d(t_data *gameinfo)
{
	gameinfo->playera += 0.02;
	if (gameinfo->playera > PI*2)
		gameinfo->playera -= PI*2;
	gameinfo->playerdx = (int)((cos(gameinfo->playera) * 5));
	gameinfo->playerdy = (int)((sin(gameinfo->playera) * 5));
	printf("Playerx: %d\t|\tPlayery: %d\n", gameinfo->playerx, gameinfo->playery);
	printf("PlayerGridx: %d\t|\tPlayerGridy: %d\n", gameinfo->player_gridx, gameinfo->player_gridy);
	printf("Playera: %f\t|\tRaya: %f\n", gameinfo->playera, gameinfo->raya);
	ft_clear(gameinfo);
	ft_raycast_horizontal(gameinfo);
	ft_raycast_vertical(gameinfo);
	ft_draw_minimap(gameinfo);
	ft_draw_player(gameinfo, gameinfo->playerx, gameinfo->playery, 10197915, 24);
	printf("DistanceH :%f  DistanceV: %f", gameinfo->distanceH, gameinfo->distanceV);
	if (gameinfo->distanceH < gameinfo->distanceV)
	{
		ft_line(gameinfo, gameinfo->playerx, gameinfo->playery, gameinfo->rayxH, gameinfo->rayyH, 65280);
		ft_draw3d(gameinfo, gameinfo->distanceH);
	}
	else if (gameinfo->distanceH > gameinfo->distanceV)
	{
		ft_line(gameinfo, gameinfo->playerx, gameinfo->playery, gameinfo->rayxV, gameinfo->rayyV, 65280);
		ft_draw3d(gameinfo, gameinfo->distanceV);
	}
}

void	moves(int key, t_data *gameinfo)
{
	if (key == XK_w)
		move_w(gameinfo);
	else if (key == XK_s)
		move_s(gameinfo);
	else if (key == XK_a)
		move_a(gameinfo);
	else if (key == XK_d)
		move_d(gameinfo);
}

//Events for key press
int	keys(int key, t_data *gameinfo)
{
	if (key == XK_Escape)
	{
		terminate_prog(gameinfo, EXIT_SUCCESS);
	}
	else
	{
		moves(key, gameinfo);
	}
	return (0);
}

//Exit clicking on x
int	x_button(t_data *gameinfo)
{
	terminate_prog(gameinfo, EXIT_SUCCESS);
	return (0);
}
