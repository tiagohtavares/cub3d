/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:05:36 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/30 12:11:59 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/errors.h"

int	main(int argc, char **argv)
{
	t_data	g;

	if (argc != 2)
	{
		ft_error(ERR_USE, NULL, EXIT_FAILURE);
	}
	g.file_path = ft_strdup(argv[1]);
	ft_init(&g);
	// mlx_mouse_hide(g.mlx, g.mlx_window); // TMP: Decide if it stays here or mouse function, here hides the mouse from the beggining, seems right | also leaks
	mlx_hook(g.mlx_window, 17, (1L << 0), x_button, &g);
	mlx_key_hook(g.mlx_window, &keys, &g);
	mlx_hook(g.mlx_window, 6, (1L << 6), &mouse, &g); // Mouse Hook
	mlx_loop_hook(g.mlx, ft_raycast, &g);
	mlx_loop(g.mlx);
	terminate_prog(&g, EXIT_SUCCESS);
	return (0);
}
