/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:05:36 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/24 10:18:41 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/error.h"

int	main(int argc, char **argv)
{
	t_data	g;

	if (argc != 2)
	{
		error(ERROR_USE, NULL, EXIT_FAILURE);
	}
	g.map_file = ft_strdup(argv[1]);
	ft_init(&g);
	mlx_hook(g.mlx_window, 17, (1L << 0), x_button, &g);
	mlx_key_hook(g.mlx_window, &keys, &g);
	mlx_loop(g.mlx);
	terminate_prog(&g, EXIT_SUCCESS);
	return (0);
}
