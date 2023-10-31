/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:07:10 by ttavares          #+#    #+#             */
/*   Updated: 2023/10/31 13:00:13 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init(t_data *gameinfo) // Initialize struct
{
	gameinfo->map = NULL;
	gameinfo->playerx = 0;
	gameinfo->playery = 0;
	gameinfo->player_gridx = 0;
	gameinfo->player_gridy = 0;
	gameinfo->map_sizex = 0;
	gameinfo->map_sizey = 0;
	gameinfo->playera = PI / 2;
	gameinfo->playerdx = (int)((cos(gameinfo->playera) * 5));
	gameinfo->playerdy = (int)((sin(gameinfo->playera) * 5));
	gameinfo->map = ft_read_map(gameinfo->map_file, gameinfo->map);
	ft_map_size(gameinfo);
	ft_get_player_position(gameinfo);
	gameinfo->mlx = mlx_init();
	gameinfo->mlx_window = mlx_new_window(gameinfo->mlx, W_WIDTH, W_HEIGHT, "cub3d");
}
