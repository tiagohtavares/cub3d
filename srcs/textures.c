/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:39:15 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/22 01:45:03 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_load_texture(t_data *gameinfo)
{
	int	i;
	int j;
	unsigned char *pixel;

	i = 0;
	while (i < 4)
	{
		gameinfo->image[i].x = 0;
		gameinfo->image[i].y = 0;
		gameinfo->image[i].image = mlx_xpm_file_to_image(gameinfo->mlx, gameinfo->path[i], &gameinfo->image[i].x, &gameinfo->image[i].y);
		if (gameinfo->image[i].image == NULL)
		{
			ft_printf("Error opening the image!\n");
			exit(0);	//Make it clear memory before exit
		}
		gameinfo->image[i].addr = mlx_get_data_addr(gameinfo->image[i].image, &gameinfo->image[i].bpp, &gameinfo->image[i].line_length, &gameinfo->image[i].endian);
		gameinfo->image[i].texture = malloc(gameinfo->image[i].x * gameinfo->image[i].y * sizeof(int));
		j = 0;
		while(j < gameinfo->image[i].x * gameinfo->image[i].y)
		{
			pixel = (unsigned char *)(gameinfo->image[i].addr + j * (gameinfo->image[i].bpp / 8));
			gameinfo->image[i].texture[j] = (pixel[2] << 16) | (pixel[1] << 8) | (pixel[0] << 0);
			j++;
		}
		printf("i: %d || img.x: %d || img.y: %d \n", i, gameinfo->image[i].x, gameinfo->image[i].y);
		i++;
	}
}

void	ft_texture(t_data *gameinfo)
{
	gameinfo->path[0] = "assets/imgs/mossy_64.xpm"; // N
	gameinfo->path[1] = "assets/imgs/brown_64.xpm"; // E
	gameinfo->path[2] = "assets/imgs/brick_64.xpm"; // S
	gameinfo->path[3] = "assets/imgs/gray_64.xpm"; // W
	gameinfo->floorcolor = C_WHITE;
	gameinfo->ceilingcolor = C_BLUE;
	ft_load_texture(gameinfo);
}

void	ft_set_pixel(t_data *gameinfo, int x, int y, int color)
{
	int	index;

	index = (y * gameinfo->line_length) + (x * (gameinfo->bpp/8));
	*(int *)(gameinfo->main_addr + index) = color;
}
