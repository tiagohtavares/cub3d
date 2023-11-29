/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:05:36 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/29 15:34:48 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/errors.h"


int	mouse(int x, int y, t_data *g)
{
/* 	double	olddirx;
	double	oldplanex;

	olddirx = g->inidirx;
	g->inidirx = g->inidirx * cos(-0.1) - g->inidiry * sin(-0.1);
	g->inidiry = olddirx * sin(-0.1) + g->inidiry * cos(-0.1);
	oldplanex = g->planex;
	g->planex = g->planex * cos(-0.1) - g->planey * sin(-0.1);
	g->planey = oldplanex * sin(-0.1) + g->planey * cos(-0.1);

	olddirx = g->inidirx;
	g->inidirx = g->inidirx * cos(0.1) - g->inidiry * sin(0.1);
	g->inidiry = olddirx * sin(0.1) + g->inidiry * cos(0.1);
	oldplanex = g->planex;
	g->planex = g->planex * cos(0.1) - g->planey * sin(0.1);
	g->planey = oldplanex * sin(0.1) + g->planey * cos(0.1);

	ft_raycast(g); */
	(void)g;
	printf("%d %d\n", x, y); // REMOVE
	return (0);
}


int	main(int argc, char **argv)
{
	t_data	g;

	if (argc != 2)
	{
		ft_error(ERR_USE, NULL, EXIT_FAILURE);
	}
	g.file_path = ft_strdup(argv[1]);
	ft_init(&g);
	mlx_hook(g.mlx_window, 17, (1L << 0), x_button, &g);
	mlx_key_hook(g.mlx_window, &keys, &g);
	// mlx_hook(g.mlx_window, 6, (1L << 6), &mouse, &g);
	mlx_loop(g.mlx);
	terminate_prog(&g, EXIT_SUCCESS);
	return (0);
}
