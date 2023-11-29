/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:01:06 by heda-sil          #+#    #+#             */
/*   Updated: 2023/11/29 18:34:12 by heda-sil         ###   ########.fr       */
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
			if ((i >= (W_WIDTH / 2) + 2 && j == (W_HEIGHT / 2) ) || \
			(j >= (W_HEIGHT / 2) + 2 && (i == (W_WIDTH / 2))) || \
			(i <= (W_WIDTH / 2) - 2 && j == (W_HEIGHT / 2) ) || \
			(j <= (W_HEIGHT / 2) - 2 && (i == (W_WIDTH / 2))))
				ft_set_pixel(game, i, j, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

// TODO: Change size of grid to macro
void	ft_draw_square(t_data *game, int x, int y, int color)
{
	int	i;
	int	j;
/* 	int	width;
	int	height;

	width = MAP_WIDTH;
	height = MAP_HEIGHT;
	printf("%d %d\n", x, y);
	if (y > 4 && x > 4)
	{
		if (game->map[(x / MAP_WIDTH) - 4][(y / MAP_HEIGHT) - 4] == '1')
		{
			width = MAP_WIDTH / 2;
			height = MAP_HEIGHT / 2;
		}
	} */
	i = 0;
	while(i < MAP_HEIGHT)
	{
		j = 0;
		while(j < MAP_WIDTH)
		{
			if(i == 0)
				ft_set_pixel(game, x + i, y + j, color);
			if(i == MAP_HEIGHT - 1)
				ft_set_pixel(game, x + i + 1, y + j, color);
			if(j == 0)
				ft_set_pixel(game, x + i, y + j, color);
			if(j == MAP_WIDTH - 1)
				ft_set_pixel(game, x + i, y + j + 1, color);
			ft_set_pixel(game, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

// TODO: Change color of squares and also size to a macro
// TODO: Find how the hell we storing player grid pos
void	ft_draw_minimap(t_data *game)
{
	int	i;
	int	j;

	i = -game->mapy;
	while(game->map[i + game->mapy])
	{
		j = -game->mapx;
		while(game->map[i + game->mapy][j + game->mapx])
		{
			if(game->map[i + game->mapy][j + game->mapx] == '0')
				ft_draw_square(game, (j + game->mapx) * MAP_WIDTH + 4, (i + game->mapy) * MAP_HEIGHT + 4, C_WHITE);
			else if(game->map[i + game->mapy][j + game->mapx] == '1')
				ft_draw_square(game, (j + game->mapx) * MAP_WIDTH + 4, (i + game->mapy) * MAP_HEIGHT + 4, C_BLACK);
			else if (ft_strchr(PLAYER, game->map[i + game->mapy][j + game->mapx]))
			{
				ft_draw_square(game, ((j + game->mapx) * MAP_WIDTH) + 4, ((i + game->mapy) * MAP_HEIGHT) + 4, C_BLUE);
			}
			else if (game->map[game->mapy][game->mapx] == 'D')
				ft_draw_square(game, (j + game->mapx) * MAP_WIDTH + 4, (i + game->mapy) * MAP_HEIGHT + 4, C_ORANGE);
			j++;
		}
		i++;
	}
}
