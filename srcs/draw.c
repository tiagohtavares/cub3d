/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:20:13 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/14 11:16:47 by heda-sil         ###   ########.fr       */
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
