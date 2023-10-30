/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:20:13 by ttavares          #+#    #+#             */
/*   Updated: 2023/10/30 16:59:19 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//Draws player on top of map
void	ft_draw_player(t_data *gameinfo, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while(i < 8)
	{
		j = 0;
		while(j < 8)
		{
			mlx_pixel_put(gameinfo->mlx, gameinfo->mlx_window, x + i, y + j, color);
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
	while(i < 32)
	{
		j = 0;
		while(j < 32)
		{
			if(i == 0)
				mlx_pixel_put(gameinfo->mlx, gameinfo->mlx_window, x + i - 1, y + j, 0);
			if(i == 31)
				mlx_pixel_put(gameinfo->mlx, gameinfo->mlx_window, x + i + 1, y + j, 0);
			if(j == 0)
				mlx_pixel_put(gameinfo->mlx, gameinfo->mlx_window, x + i, y + j - 1, 0);
			if(j == 31)
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
				ft_draw_square(gameinfo, j * 32, i * 32, 16777215);
			else if(gameinfo->map[i][j] == '1')
				ft_draw_square(gameinfo, j * 32, i * 32, 16711680);
			else if(gameinfo->map[i][j] == 'N')
				ft_draw_square(gameinfo, j * 32, i * 32, 16777215);
			j++;
		}
		i++;
	}
}
