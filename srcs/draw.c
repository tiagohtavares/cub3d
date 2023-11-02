/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:20:13 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/02 17:37:19 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//Draws player on top of map
void	ft_draw_player(t_data *gameinfo, int x, int y, int color, int size)
{
	int	i;
	int	j;

	i = 0;
	while(i < size)
	{
		j = 0;
		while(j < size)
		{
			mlx_pixel_put(gameinfo->mlx, gameinfo->mlx_window, x + i - (size/2), y + j - (size/2), color);
			j++;
		}
		i++;
	}
}

//Draw a square starting at x y
void	ft_draw_square(t_data *gameinfo, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while(i < WIDTH)
	{
		j = 0;
		while(j < HEIGHT)
		{
			if(i == 0)
				mlx_pixel_put(gameinfo->mlx, gameinfo->mlx_window, x + i - 1, y + j, 0);
			if(i == WIDTH - 1)
				mlx_pixel_put(gameinfo->mlx, gameinfo->mlx_window, x + i + 1, y + j, 0);
			if(j == 0)
				mlx_pixel_put(gameinfo->mlx, gameinfo->mlx_window, x + i, y + j - 1, 0);
			if(j == HEIGHT - 1)
				mlx_pixel_put(gameinfo->mlx, gameinfo->mlx_window, x + i, y + j + 1, 0);
			mlx_pixel_put(gameinfo->mlx, gameinfo->mlx_window, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

//Draws minimap
void	ft_draw_minimap(t_data *gameinfo)
{
	int	i;
	int	j;

	i = 0;
	while(gameinfo->map[i])
	{
		j = 0;
		while(gameinfo->map[i][j])
		{
			if(gameinfo->map[i][j] == '0')
				ft_draw_square(gameinfo, j * WIDTH, i * HEIGHT, 16777215);
			else if(gameinfo->map[i][j] == '1')
				ft_draw_square(gameinfo, j * WIDTH, i * HEIGHT, 16711680);
			else if(gameinfo->map[i][j] == 'N')
				ft_draw_square(gameinfo, j * WIDTH, i * HEIGHT, 16777215);
			j++;
		}
		i++;
	}
}

void	ft_clear(t_data *gameinfo)
{
	int	i = 0;

	while(i < W_HEIGHT)
	{
		mlx_pixel_put(gameinfo->mlx, gameinfo->mlx_window, 640, i, 0);
		i++;
	}
}

void	ft_draw3d(t_data *gameinfo, int distance)
{
	printf("Distance: %d\n" , distance);
	int	y = 0;
	int height = 300;
	height = height - distance ;
	while(y < height)
	{
		mlx_pixel_put(gameinfo->mlx, gameinfo->mlx_window, 640, 360 + y - (height / 2), 0xFFFFFF);
		y++;
	}
}
