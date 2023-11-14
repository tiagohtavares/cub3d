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
#include "../includes/errors.h"
#include <math.h>
#include <stdio.h>

void	move_w(t_data *gameinfo)
{
	if(gameinfo->map[(int)(gameinfo->playery)][(int)(gameinfo->playerx + gameinfo->inidirx * 0.2)] != '1')
		gameinfo->playerx += gameinfo->inidirx * 0.2;
	if(gameinfo->map[(int)(gameinfo->playery + gameinfo->inidiry * 0.2)][(int)(gameinfo->playerx)] != '1')
		gameinfo->playery += gameinfo->inidiry * 0.2;
	ft_raycast(gameinfo);
}

void	move_s(t_data *gameinfo)
{
	if(gameinfo->map[(int)(gameinfo->playery)][(int)(gameinfo->playerx - gameinfo->inidirx * 0.2)] != '1')
		gameinfo->playerx -= gameinfo->inidirx * 0.2;
	if(gameinfo->map[(int)(gameinfo->playery - gameinfo->inidiry * 0.2)][(int)(gameinfo->playerx)] != '1')
		gameinfo->playery -= gameinfo->inidiry * 0.2;
	ft_raycast(gameinfo);
}

void	move_left(t_data *gameinfo)
{
	double	olddirx;
	double	oldplanex;

	olddirx = gameinfo->inidirx;
	gameinfo->inidirx = gameinfo->inidirx * cos(-0.1) - gameinfo->inidiry * sin(-0.1);
	gameinfo->inidiry = olddirx * sin(-0.1) + gameinfo->inidiry * cos(-0.1);

	oldplanex = gameinfo->planex;
	gameinfo->planex = gameinfo->planex * cos(-0.1) - gameinfo->planey * sin(-0.1);
	gameinfo->planey = oldplanex * sin(-0.1) + gameinfo->planey * cos(-0.1);
	ft_raycast(gameinfo);
}

void	move_right(t_data *gameinfo)
{
	double	olddirx;
	double	oldplanex;

	olddirx = gameinfo->inidirx;
	gameinfo->inidirx = gameinfo->inidirx * cos(0.1) - gameinfo->inidiry * sin(0.1);
	gameinfo->inidiry = olddirx * sin(0.1) + gameinfo->inidiry * cos(0.1);

	oldplanex = gameinfo->planex;
	gameinfo->planex = gameinfo->planex * cos(0.1) - gameinfo->planey * sin(0.1);
	gameinfo->planey = oldplanex * sin(0.1) + gameinfo->planey * cos(0.1);
	ft_raycast(gameinfo);
}

void	move_d(t_data *gameinfo)
{
	if(gameinfo->map[(int)(gameinfo->playery + gameinfo->inidirx * 0.2)][(int)(gameinfo->playerx)] != '1')
		gameinfo->playery += gameinfo->inidirx * 0.2;
	if(gameinfo->map[(int)(gameinfo->playery)][(int)(gameinfo->playerx - gameinfo->inidiry * 0.2)] != '1')
		gameinfo->playerx -= gameinfo->inidiry * 0.2;
	ft_raycast(gameinfo);
}

void	move_a(t_data *gameinfo)
{
	if(gameinfo->map[(int)(gameinfo->playery - gameinfo->inidirx * 0.2)][(int)(gameinfo->playerx)] != '1')
		gameinfo->playery -= gameinfo->inidirx * 0.2;
	if(gameinfo->map[(int)(gameinfo->playery)][(int)(gameinfo->playerx + gameinfo->inidiry * 0.2)] != '1')
		gameinfo->playerx += gameinfo->inidiry * 0.2;
	ft_raycast(gameinfo);
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
	else if (key == XK_Right)
		move_right(gameinfo);
	else if (key == XK_Left)
		move_left(gameinfo);
}

int	keys(int key, t_data *gameinfo)
{
	if (key == XK_Escape)
		terminate_prog(gameinfo, EXIT_SUCCESS);
	else
	{
		ft_clear(gameinfo);
		moves(key, gameinfo);
	}
	ft_raycast(gameinfo);
	return (0);
}

//Exit clicking on x
int	x_button(t_data *gameinfo)
{
	terminate_prog(gameinfo, EXIT_SUCCESS);
	return (0);
}
