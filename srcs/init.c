/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:07:10 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/14 11:19:39 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/read_map.h"

void	ft_start(t_data *gameinfo)
{
	ft_read_file(gameinfo->file_path, gameinfo);
	// gameinfo->map = ft_read_map(gameinfo->map_file, gameinfo->map);
	gameinfo->mlx = mlx_init();
	gameinfo->mlx_window = mlx_new_window(gameinfo->mlx, W_WIDTH, W_HEIGHT, "cub3d");
	ft_get_player_position(gameinfo);
	ft_raycast(gameinfo);
}

void	ft_init(t_data *gameinfo)
{
	gameinfo->mlx = NULL;
	gameinfo->mlx_window = NULL;
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
	gameinfo->map_file = NULL;
	gameinfo->map_width = 0;
	gameinfo->map_height = 0;
	gameinfo->textures.ceiling = -1;
	gameinfo->textures.floor = -1;
	gameinfo->textures.walls = ft_calloc(4, sizeof(*gameinfo->textures.walls));
	gameinfo->textures.nbr_txt = 0;
	ft_start(gameinfo);
	ft_map_size(gameinfo);
}
