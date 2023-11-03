/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 04:42:32 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/03 06:21:08 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	ft_distance(double x1, double y1, double x2, double y2) // Distance between 2 points
{
	double	x_diff;
	double	y_diff;

	x_diff = x1 - x2;
	y_diff = y1 - y2;

	return(sqrt(x_diff * x_diff + y_diff * y_diff));
}

void	ft_line(t_data *gameinfo, int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	sx = (x1 < x2) ? 1 : -1;
	sy = (y1 < y2) ? 1 : -1;
	err = dx - dy;
	while (x1 != x2 || y1 != y2)
	{
		mlx_pixel_put(gameinfo->mlx, gameinfo->mlx_window, x1, y1, 0);
		e2 = 2* err;
		if (e2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}
