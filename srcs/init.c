/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:07:10 by ttavares          #+#    #+#             */
/*   Updated: 2023/10/30 16:54:23 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init(t_data *gameinfo) // Initialize struct
{
	gameinfo->map = NULL;
	gameinfo->playerx = 0;
	gameinfo->playery = 0;
	gameinfo->map_sizex = 0;
	gameinfo->map_sizey = 0;
	gameinfo->playera = PI / 2;
	gameinfo->playerdx = (int)((cos(gameinfo->playera) * 5));
	gameinfo->playerdy = (int)((sin(gameinfo->playera) * 5));
	gameinfo->map = ft_read_map("./assets/test.cub", gameinfo->map);
	ft_map_size(gameinfo);
	ft_get_player_position(gameinfo);
	gameinfo->mlx = mlx_init();
	gameinfo->mlx_window = mlx_new_window(gameinfo->mlx, 1280, 720, "cub3d");
}
