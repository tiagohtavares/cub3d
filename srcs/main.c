/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:05:36 by ttavares          #+#    #+#             */
/*   Updated: 2023/10/31 12:15:41 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/error.h"

int	main(int argc, char **argv)
{
	t_data gameinfo;

	if (argc != 2)
	{
		error(ERROR_USE, NULL, EXIT_FAILURE);
	}
	gameinfo.map_file = ft_strdup(argv[1]);
	ft_init(&gameinfo);
	ft_draw_minimap(&gameinfo);
	ft_draw_player(&gameinfo, gameinfo.playerx, gameinfo.playery, 10197915);
	ft_draw_player(&gameinfo, gameinfo.playerx - (gameinfo.playerdx * 4), gameinfo.playery - (gameinfo.playerdy * 4), 39680);
	mlx_hook(gameinfo.mlx_window, 17, (1L << 0), x_button, &gameinfo);
	mlx_key_hook(gameinfo.mlx_window, &keys, &gameinfo);
	mlx_loop(gameinfo.mlx);
	terminate_prog(&gameinfo, EXIT_SUCCESS);
	return (0);
}
