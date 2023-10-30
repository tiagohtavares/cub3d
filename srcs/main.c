/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:05:36 by ttavares          #+#    #+#             */
/*   Updated: 2023/10/30 17:01:21 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data gameinfo;
	
	ft_init(&gameinfo);
	ft_draw_minimap(&gameinfo);
	ft_draw_player(&gameinfo, gameinfo.playerx, gameinfo.playery, 10197915);
	ft_draw_player(&gameinfo, gameinfo.playerx - (gameinfo.playerdx * 4), gameinfo.playery - (gameinfo.playerdy * 4), 39680);
	mlx_hook(gameinfo.mlx_window, 17, (1L << 0), x_button, &gameinfo);
	mlx_key_hook(gameinfo.mlx_window, &keys, &gameinfo);
	mlx_loop(gameinfo.mlx);
	(void)argc;
	(void)argv;
	return (0);
}
