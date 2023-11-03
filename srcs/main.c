/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:05:36 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/03 15:26:30 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/errors.h"

int	main(int argc, char **argv)
{
	t_data gameinfo;

	if (argc != 2)
	{
		ft_error(ERR_USE, NULL, EXIT_FAILURE);
	}
	gameinfo.map_file = ft_strdup(argv[1]);
	ft_init(&gameinfo);
	ft_draw_minimap(&gameinfo);
	ft_draw_player(&gameinfo, gameinfo.playerx, gameinfo.playery, 10197915);
	ft_draw_player(&gameinfo, gameinfo.playerx - (gameinfo.playerdx * 4), gameinfo.playery - (gameinfo.playerdy * 4), 39680);
	// gameinfo.textures.walls[N].path = "./assets/textures/wall.xpm";
	// gameinfo.textures.walls[N].height = 32;
	// gameinfo.textures.walls[N].width = 32;
	// gameinfo.textures.walls[N].img = mlx_xpm_file_to_image(gameinfo.mlx, gameinfo.textures.walls[N].path, &gameinfo.textures.walls[N].width, &gameinfo.textures.walls[N].width);
	// mlx_put_image_to_window(gameinfo.mlx, gameinfo.mlx_window, gameinfo.textures.walls[N].img, 10, 10);
	mlx_hook(gameinfo.mlx_window, 17, (1L << 0), x_button, &gameinfo);
	mlx_key_hook(gameinfo.mlx_window, &keys, &gameinfo);
	mlx_loop(gameinfo.mlx);
	ft_map_print(gameinfo.map);
	terminate_prog(&gameinfo, EXIT_SUCCESS);
	return (0);
}
