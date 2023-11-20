/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:21:46 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/20 17:16:50 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_draw_vertical(t_data *gameinfo, int x, int start, int end, int color)
{
	while(start <= end)
	{
		mlx_pixel_put(gameinfo->mlx, gameinfo->mlx_window, x , start , color);
		start++;
	}
}

void	ft_draw_buffer(t_data *gameinfo, int x,int start, int end,  int buffer[W_HEIGHT][W_WIDTH])
{
	int	f;
	int c;

	f = 0;
	c = end;
	while (f <= start)
	{
		mlx_pixel_put(gameinfo->mlx, gameinfo->mlx_window, x, f, gameinfo->floorcolor);
		f++;
	}
	while(start <= end)
	{
		mlx_pixel_put(gameinfo->mlx, gameinfo->mlx_window, x, start, buffer[start][x]);
		start++;
	}
	while (c <= W_HEIGHT)
	{
		mlx_pixel_put(gameinfo->mlx, gameinfo->mlx_window, x, c, gameinfo->ceilingcolor);
		c++;
	}
}

void	ft_clear(t_data *gameinfo)
{
	int	i;
	int	j;

	i = 0;
	while(i < W_WIDTH)
	{
		j = 0;
		while(j < W_HEIGHT)
		{
			mlx_pixel_put(gameinfo->mlx, gameinfo->mlx_window, i, j, 0);
			j++;
		}
		i++;
	}
}
