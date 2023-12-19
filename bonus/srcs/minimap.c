/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 03:28:22 by heda-sil          #+#    #+#             */
/*   Updated: 2023/12/19 03:29:20 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* Draws a crosshair */
void	ft_crosshair(t_data *game)
{
	int	i;
	int	j;

	i = (W_WIDTH / 2) - 5;
	while (i < (W_WIDTH / 2) + 5)
	{
		j = (W_HEIGHT / 2) - 5;
		while (j < (W_HEIGHT / 2) + 5)
		{
			if ((i >= (W_WIDTH / 2) + 2 && j == (W_HEIGHT / 2)) || \
			(j >= (W_HEIGHT / 2) + 2 && (i == (W_WIDTH / 2))) || \
			(i <= (W_WIDTH / 2) - 2 && j == (W_HEIGHT / 2)) || \
			(j <= (W_HEIGHT / 2) - 2 && (i == (W_WIDTH / 2))))
				ft_set_pixel(game, i, j, C_WHITE);
			j++;
		}
		i++;
	}
}

// Draws a square
void	ft_draw_square(t_data *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < MAP_HEIGHT)
	{
		j = -1;
		while (++j < MAP_WIDTH)
			ft_set_pixel(game, x + i, y + j, color);
	}
}

// Draws the minimap
void	ft_draw_minimap(t_data *g)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	while (g->map[++i])
	{
		j = -1;
		while (g->map[i][++j])
		{
			x = (j * MAP_WIDTH) + 4;
			y = (i * MAP_HEIGHT) + 4;
			ft_draw(g, g->map[i][j], x, y);
			if (!ft_get_door_state(g->door, j, i, g->nbr_doors))
				ft_draw_square(g, x, y, C_GREEN);
			else if (g->map[i][j] == 'D')
				ft_draw_square(g, x, y, C_RED);
		}
	}
	ft_draw_square(g, (g->playerx * MAP_WIDTH) - 4, \
	(g->playery * MAP_HEIGHT) - 4, C_BLUE);
}

void	ft_draw(t_data *g, char square, int x, int y)
{
	if (square == '0')
		ft_draw_square(g, x, y, C_WHITE);
	else if (square == '1')
		ft_draw_square(g, x, y, C_BLACK);
	else if (ft_strchr(PLAYER, square))
		ft_draw_square(g, x, y, C_WHITE);
}
