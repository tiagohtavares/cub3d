/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:01:06 by heda-sil          #+#    #+#             */
/*   Updated: 2023/11/29 15:39:21 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//Prints the map
void	ft_map_print(char **map)
{
	int	i;

	ft_printf("\n\n----------MAP ARRAY---------\n");
	i = -1;
	while (map[++i])
		ft_printf("%s\n", map[i]);
	ft_printf("----------END----------\n\n");
}

// Prints the file content
void	ft_file_print(t_list *file)
{
	ft_printf("\n\n----------FILE LIST----------\n");
	while (file)
	{
		ft_printf("%s", (char *)file->content);
		file = file->next;
	}
	ft_printf("----------END----------\n\n");
}

// Prints the textures content
void	ft_textures_print(t_texture texture)
{
	ft_printf("\n\n----------TEXTURES INFO---------\n");
	ft_printf("NO: %s\n", texture.wall[N].path);
	ft_printf("SO: %s\n", texture.wall[S].path);
	ft_printf("EA: %s\n", texture.wall[E].path);
	ft_printf("WE: %s\n", texture.wall[W].path);
	ft_printf("----------END----------\n\n");
}

/* Draws a crosshair */
void	ft_crosshair(t_data *game)
{
	int i;
	int	j;

	i = (W_WIDTH / 2) - 5;
	while (i < (W_WIDTH / 2) + 5)
	{
		j = (W_HEIGHT / 2) - 5;
		while (j < (W_HEIGHT / 2) + 5)
		{
			if (i == W_WIDTH / 2 || j == W_HEIGHT / 2)
				ft_set_pixel(game, i, j, 0xFFFFFF);
			j++;
		}
		i++;
	}
}
