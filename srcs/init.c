/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:07:10 by ttavares          #+#    #+#             */
/*   Updated: 2024/01/18 17:10:54 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/errors.h"

void	ft_start(t_data *g)
{
	ft_read_file(g->file_path, g);
	if (!ft_valid_chars(g->map, VALID_CHARS))
		ft_error(ERR_CHAR, g, EXIT_FAILURE);
	ft_check_map(g->map, g->map_height, g);
	g->mlx = mlx_init();
	ft_texture(g);
	g->mlx_window = mlx_new_window(g->mlx, W_WIDTH, W_HEIGHT, "cub3d");
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
	int i;

	g->map = NULL;
	g->map_file = NULL;
	g->mlx = NULL;
	g->mlx_window = NULL;
	g->mlx_main = NULL;
	g->img_n = NULL;
	g->img_s = NULL;
	g->img_e = NULL;
	g->img_w = NULL;
	g->image = ft_calloc(4, sizeof(*g->image));
	i = -1;
	while (++i < 4)
		g->image[i].image = NULL;
	g->map_width = 0;
	g->map_height = 0;
	g->ceilingcolor = -1;
	g->floorcolor = -1;
	g->textures.wall = ft_calloc(4, sizeof(*g->textures.wall));
	g->textures.nbr_txt = 0;
	ft_start(g);
}
