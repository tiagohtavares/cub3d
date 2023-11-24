/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:05:36 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/24 15:03:32 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/errors.h"

int	main(int argc, char **argv)
{
	t_data	gameinfo;

	if (argc != 2)
	{
		ft_error(ERR_USE, NULL, EXIT_FAILURE);
	}
	gameinfo.file_path = ft_strdup(argv[1]);
	ft_init(&gameinfo);
/* 	mlx_hook(gameinfo.mlx_window, 17, (1L << 0), x_button, &gameinfo);
	mlx_key_hook(gameinfo.mlx_window, &keys, &gameinfo);
	mlx_loop(gameinfo.mlx); */
	terminate_prog(&gameinfo, EXIT_SUCCESS);
	return (0);
}
