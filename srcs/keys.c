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
#include "../includes/errors.h"
#include <math.h>
#include <stdio.h>

void	move_w(t_data *gameinfo)
{
	gameinfo->playerx -= gameinfo->playerdx;
	gameinfo->playery -= gameinfo->playerdy;
	gameinfo->player_gridx = gameinfo->playerx / MAP_WIDTH;
	gameinfo->player_gridy = gameinfo->playery / MAP_HEIGHT;
	/* if (gameinfo->playerx % WIDTH == 0)
	{
		gameinfo->player_gridx--;
	}
	if (gameinfo->playery % HEIGHT == 0)
	{
		gameinfo->player_gridy--;

	} */
	printf("Px: %d\t|\tPy: %d\n", gameinfo->playerx, gameinfo->playery);
	printf("Gx: %d\t|\tGy: %d\n", gameinfo->player_gridx, gameinfo->player_gridy);
	ft_check_collisions(gameinfo->map, gameinfo->player_gridx, gameinfo->player_gridy, gameinfo);
	ft_draw_minimap(gameinfo);
	ft_draw_player(gameinfo, gameinfo->playerx, gameinfo->playery, 10197915);
	ft_draw_player(gameinfo, gameinfo->playerx - (gameinfo->playerdx * 4), gameinfo->playery - (gameinfo->playerdy * 4), 39680);
}

void	move_s(t_data *gameinfo)
{
	gameinfo->playerx += gameinfo->playerdx;
	gameinfo->playery += gameinfo->playerdy;
	gameinfo->player_gridx = gameinfo->playerx / MAP_WIDTH;
	gameinfo->player_gridy = gameinfo->playery / MAP_HEIGHT;
	/* if (gameinfo->playerx % WIDTH == 0)
	{
		gameinfo->player_gridx++;
	}
	if (gameinfo->playery % HEIGHT == 0)
	{
		gameinfo->player_gridy++;

	} */
	printf("Px: %d\t|\tPy: %d\n", gameinfo->playerx, gameinfo->playery);
	printf("Gx: %d\t|\tGy: %d\n", gameinfo->player_gridx, gameinfo->player_gridy);
	ft_check_collisions(gameinfo->map, gameinfo->playerx, gameinfo->playery, gameinfo);
	ft_draw_minimap(gameinfo);
	ft_draw_player(gameinfo, gameinfo->playerx, gameinfo->playery, 10197915);
	ft_draw_player(gameinfo, gameinfo->playerx - (gameinfo->playerdx * 4), gameinfo->playery - (gameinfo->playerdy * 4), 39680);
}

void	move_a(t_data *gameinfo)
{
	gameinfo->player_angle -= 0.1;
	if (gameinfo->player_angle < 0)
		gameinfo->player_angle += PI*2;
	gameinfo->playerdx = (int)((cos(gameinfo->player_angle) * 5));
	gameinfo->playerdy = (int)((sin(gameinfo->player_angle) * 5));
	ft_draw_minimap(gameinfo);
	ft_draw_player(gameinfo, gameinfo->playerx, gameinfo->playery, 10197915);
	ft_draw_player(gameinfo, gameinfo->playerx - (gameinfo->playerdx * 4), gameinfo->playery - (gameinfo->playerdy * 4), 39680);
}

void	move_d(t_data *gameinfo)
{
	gameinfo->player_angle += 0.1;
	if (gameinfo->player_angle > PI*2)
		gameinfo->player_angle -= PI*2;
	gameinfo->playerdx = (int)((cos(gameinfo->player_angle) * 5));
	gameinfo->playerdy = (int)((sin(gameinfo->player_angle) * 5));
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
