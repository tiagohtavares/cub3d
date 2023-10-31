/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:20:13 by ttavares          #+#    #+#             */
/*   Updated: 2023/10/31 12:15:10 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//Draws player on top of map
void	ft_draw_player(t_data *gameinfo, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while(i < WIDTH / 4)
	{
		j = 0;
		while(j < HEIGHT / 4)
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
