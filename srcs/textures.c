/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:39:15 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/21 15:41:06 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_texture(t_data *gameinfo)
{
	int	x = 0;
	int	y = 0;
	int	bites_per_pixel;
	int	size_line;
	int	endian;
	char	*img;

	// gameinfo->img_n = mlx_xpm_file_to_image(gameinfo->mlx, "assets/imgs/brown_64.xpm", gameinfo->imagex, gameinfo->imagey);
	// gameinfo->img_e = mlx_xpm_file_to_image(gameinfo->mlx, "assets/imgs/gray_64.xpm", gameinfo->imagex, gameinfo->imagey);
	// gameinfo->img_s = mlx_xpm_file_to_image(gameinfo->mlx, "assets/imgs/mossy_64.xpm", gameinfo->imagex, gameinfo->imagey);
	gameinfo->img_w = mlx_xpm_file_to_image(gameinfo->mlx, "assets/imgs/mossy_64.xpm", &x, &y);
	img = mlx_get_data_addr(gameinfo->img_w	, &bites_per_pixel,&size_line,&endian);
	gameinfo->texture_test = malloc(x * y * sizeof(int));
	for(int	i = 0;i < x * y;i++)
	{
		unsigned char *pixel = (unsigned char *)(img + i * (bites_per_pixel / 8));
		gameinfo->texture_test[i] = (pixel[2] << 16) | (pixel[1] << 8) | (pixel[0] << 0);
	}

	gameinfo->imagex = x;
	gameinfo->imagey = y;
}

void	ft_set_pixel(t_data *gameinfo, int x, int y, int color)
{
	int	index;

	index = (y * gameinfo->line_length) + (x * (gameinfo->bpp/8));
	*(int *)(gameinfo->main_addr + index) = color;
}
