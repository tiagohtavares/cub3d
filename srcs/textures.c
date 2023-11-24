/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:39:15 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/24 11:31:41 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_load_image(t_data *g, int i)
{
	g->image[i].x = 0;
	g->image[i].y = 0;
	g->image[i].image = mlx_xpm_file_to_image(g->mlx, g->path[i],
			&g->image[i].x, &g->image[i].y);
	if (g->image[i].image == NULL)
	{
		ft_printf("Error opening the image!\n");
		exit(0);
	}
}

void	ft_load_texture(t_data *g)
{
	int				i;
	int				j;
	unsigned char	*pixel;

	i = 0;
	while (i < 4)
	{
		ft_load_image(g, i);
		g->image[i].addr = mlx_get_data_addr(g->image[i].image,
				&g->image[i].bpp,
				&g->image[i].line_length, &g->image[i].endian);
		g->image[i].texture = malloc(g->image[i].x
				* g->image[i].y * sizeof(int));
		j = 0;
		while (j < g->image[i].x * g->image[i].y)
		{
			pixel = (unsigned char *)(g->image[i].addr + j
					* (g->image[i].bpp / 8));
			g->image[i].texture[j] = (pixel[2] << 16)
				| (pixel[1] << 8) | (pixel[0] << 0);
			j++;
		}
		i++;
	}
}

void	ft_texture(t_data *g)
{
	g->path[0] = "assets/imgs/mossy_64.xpm";
	g->path[1] = "assets/imgs/brown_64.xpm";
	g->path[2] = "assets/imgs/brick_64.xpm";
	g->path[3] = "assets/imgs/gray_64.xpm";
	g->floorcolor = C_GREEN;
	g->ceilingcolor = C_BLUE;
	ft_load_texture(g);
}

void	ft_set_pixel(t_data *g, int x, int y, int color)
{
	int	index;

	index = (y * g->line_length) + (x * (g->bpp / 8));
	*(int *)(g->main_addr + index) = color;
}
