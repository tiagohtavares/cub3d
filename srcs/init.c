/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:07:10 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/06 17:45:38 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/read_map.h"

 // Initialize struct
void	ft_init(t_data *gameinfo)
{
	gameinfo->mlx = NULL;
	gameinfo->mlx_window = NULL;
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
	gameinfo->map_file = NULL;
	gameinfo->playerdx = (int)((cos(gameinfo->player_angle) * 5));
	gameinfo->playerdy = (int)((sin(gameinfo->player_angle) * 5));
	ft_read_file(gameinfo->file_path, gameinfo);
	ft_map_size(gameinfo);
	ft_get_player_position(gameinfo);
	gameinfo->mlx = mlx_init();
	gameinfo->mlx_window = mlx_new_window(gameinfo->mlx, W_WIDTH, W_HEIGHT, "cub3d");
}
