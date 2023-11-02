/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:22:53 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/02 17:02:54 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_line(t_data *gameinfo, int x1, int y1, int x2, int y2, int color)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    while (x1 != x2 || y1 != y2) {
        // Plot the current point (x1, y1) here
        // In this example, we just print the coordinates, but in graphics, you would actually draw the point
        mlx_pixel_put(gameinfo->mlx, gameinfo->mlx_window, x1, y1, color);

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }

    // Plot the endpoint (x2, y2) here
    printf("(%d, %d)\n", x2, y2);
}

double	ft_distance(double x1, double y1, double x2, double y2)
{
	double result;

	result = sqrt ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	return (result);
}
