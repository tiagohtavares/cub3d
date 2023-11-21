/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:07:10 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/21 15:41:53 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_start(t_data *gameinfo)
{
	gameinfo->map = ft_read_map(gameinfo->map_file, gameinfo->map);
	gameinfo->mlx = mlx_init();
	gameinfo->mlx_window = mlx_new_window(gameinfo->mlx, W_WIDTH, W_HEIGHT, "cub3d");
	ft_texture(gameinfo);
	gameinfo->main_h = W_HEIGHT;
	gameinfo->main_w = W_WIDTH;
	gameinfo->mlx_main = mlx_new_image(gameinfo->mlx, gameinfo->main_w, gameinfo->main_h);
	gameinfo->main_addr = mlx_get_data_addr(gameinfo->mlx_main, &gameinfo->bpp, &gameinfo->line_length, &gameinfo->endian);
	ft_get_player_position(gameinfo);
	ft_raycast(gameinfo);
}

void	ft_init(t_data *gameinfo)
{
	gameinfo->map = NULL;
	gameinfo->playerx = 0;
	gameinfo->playery = 0;
	gameinfo->inidirx = 0;
	gameinfo->inidiry = 0;
	gameinfo->planex = 1;
	gameinfo->planey = 0;
	gameinfo->camerax = 0;
	gameinfo->raydirx = 0;
	gameinfo->raydiry = 0;
	gameinfo->mapx = 0;
	gameinfo->mapy = 0;
	gameinfo->distancex = 0;
	gameinfo->distancey = 0;
	gameinfo->deltax = 0;
	gameinfo->deltay = 0;
	gameinfo->perpwalldistance = 0;
	gameinfo->stepx = 0;
	gameinfo->stepy = 0;
	gameinfo->hit = 0;
	gameinfo->side = 0;
	gameinfo->lineh = 0;
	gameinfo->color = 0;
	gameinfo->floorcolor = C_WHITE;
	gameinfo->ceilingcolor = C_BLUE;
	ft_start(gameinfo);
}
