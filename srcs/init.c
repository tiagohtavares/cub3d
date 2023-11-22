/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:07:10 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/22 17:16:40 by ttavares         ###   ########.fr       */
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
	ft_start(gameinfo);
}
