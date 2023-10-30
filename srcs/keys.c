/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys->c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student->42porto->com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:14:44 by ttavares          #+#    #+#             */
/*   Updated: 2023/10/30 16:59:45 by ttavares         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>

void	move_w(t_data *gameinfo)
{
	gameinfo->playerx -= gameinfo->playerdx;
	gameinfo->playery -= gameinfo->playerdy;
	ft_draw_minimap(gameinfo);
	ft_draw_player(gameinfo, gameinfo->playerx, gameinfo->playery, 10197915);
	ft_draw_player(gameinfo, gameinfo->playerx - (gameinfo->playerdx * 4), gameinfo->playery - (gameinfo->playerdy * 4), 39680);
}

void	move_s(t_data *gameinfo)
{
	gameinfo->playerx += gameinfo->playerdx;
	gameinfo->playery += gameinfo->playerdy;
	ft_draw_minimap(gameinfo);
	ft_draw_player(gameinfo, gameinfo->playerx, gameinfo->playery, 10197915);
	ft_draw_player(gameinfo, gameinfo->playerx - (gameinfo->playerdx * 4), gameinfo->playery - (gameinfo->playerdy * 4), 39680);
}

void	move_a(t_data *gameinfo)
{
	gameinfo->playera -= 0.1;
	if (gameinfo->playera < 0)
		gameinfo->playera += PI*2;
	gameinfo->playerdx = (int)((cos(gameinfo->playera) * 5));
	gameinfo->playerdy = (int)((sin(gameinfo->playera) * 5));
	ft_draw_minimap(gameinfo);
	ft_draw_player(gameinfo, gameinfo->playerx, gameinfo->playery, 10197915);
	ft_draw_player(gameinfo, gameinfo->playerx - (gameinfo->playerdx * 4), gameinfo->playery - (gameinfo->playerdy * 4), 39680);
}

void	move_d(t_data *gameinfo)
{
	gameinfo->playera += 0.1;
	if (gameinfo->playera > PI*2)
		gameinfo->playera -= PI*2;
	gameinfo->playerdx = (int)((cos(gameinfo->playera) * 5));
	gameinfo->playerdy = (int)((sin(gameinfo->playera) * 5));
	ft_draw_minimap(gameinfo);
	ft_draw_player(gameinfo, gameinfo->playerx, gameinfo->playery, 10197915);
	ft_draw_player(gameinfo, gameinfo->playerx - (gameinfo->playerdx * 4), gameinfo->playery - (gameinfo->playerdy * 4), 39680);
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
		exit(0);
	else
		moves(key, gameinfo);
	return (0);
}

//Exit clicking on x
int	x_button(t_data *gameinfo)
{
	(void)gameinfo;
	exit(0);
	return (0);
}
