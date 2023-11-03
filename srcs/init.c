/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:07:10 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/03 15:33:29 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

 // Initialize struct
void	ft_init(t_data *gameinfo)
{
	gameinfo->map = NULL;
	gameinfo->mlx = NULL;
	gameinfo->mlx_window = NULL;
	gameinfo->map = NULL;
	gameinfo->playerx = 0;
	gameinfo->playery = 0;
	gameinfo->player_gridx = 0;
	gameinfo->player_gridy = 0;
	gameinfo->map_width = 0;
	gameinfo->map_height = 0;
	gameinfo->textures.ceiling = 0;	//TMP - Prob change the value
	gameinfo->textures.floor = 0;	//TMP - Prob change to -1 or something
	gameinfo->textures.walls = ft_calloc(4, sizeof(*gameinfo->textures.walls));
	gameinfo->player_angle = PI / 2;
	gameinfo->playerdx = (int)((cos(gameinfo->player_angle) * 5));
	gameinfo->playerdy = (int)((sin(gameinfo->player_angle) * 5));
	gameinfo->map = ft_read_map(gameinfo->map_file, gameinfo->map, gameinfo);
	ft_map_size(gameinfo);
	ft_get_player_position(gameinfo);
	gameinfo->mlx = mlx_init();
	gameinfo->mlx_window = mlx_new_window(gameinfo->mlx, W_WIDTH, W_HEIGHT, "cub3d");
}
