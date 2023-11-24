/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:07:10 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/24 12:38:53 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_start(t_data *g)
{
	g->map = ft_read_map(g->map_file, g->map);
	free(g->map_file);
	g->mlx = mlx_init();
	g->mlx_window = mlx_new_window(g->mlx, W_WIDTH, W_HEIGHT, "cub3d");
	ft_texture(g);
	g->main_h = W_HEIGHT;
	g->main_w = W_WIDTH;
	g->mlx_main = mlx_new_image(g->mlx, g->main_w, g->main_h);
	g->main_addr = mlx_get_data_addr(g->mlx_main, &g->bpp,
			&g->line_length, &g->endian);
	ft_get_player_position(g);
	ft_raycast(g);
}

void	ft_init(t_data *g)
{
	ft_start(g);
}
