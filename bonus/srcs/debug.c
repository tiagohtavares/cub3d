/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:01:06 by heda-sil          #+#    #+#             */
/*   Updated: 2023/12/04 13:39:29 by heda-sil         ###   ########.fr       */
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
	int	i;
	int	j;

	i = (W_WIDTH / 2) - 5;
	while (i < (W_WIDTH / 2) + 5)
	{
		j = (W_HEIGHT / 2) - 5;
		while (j < (W_HEIGHT / 2) + 5)
		{
			if ((i >= (W_WIDTH / 2) + 2 && j == (W_HEIGHT / 2)) || \
			(j >= (W_HEIGHT / 2) + 2 && (i == (W_WIDTH / 2))) || \
			(i <= (W_WIDTH / 2) - 2 && j == (W_HEIGHT / 2)) || \
			(j <= (W_HEIGHT / 2) - 2 && (i == (W_WIDTH / 2))))
				ft_set_pixel(game, i, j, C_WHITE);
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

	i = 0;
	while (i < MAP_HEIGHT)
	{
		j = 0;
		while (j < MAP_WIDTH)
		{
			if (i == 0)
				ft_set_pixel(game, x + i, y + j, color);
			if (i == MAP_HEIGHT - 1)
				ft_set_pixel(game, x + i + 1, y + j, color);
			if (j == 0)
				ft_set_pixel(game, x + i, y + j, color);
			if (j == MAP_WIDTH - 1)
				ft_set_pixel(game, x + i, y + j + 1, color);
			ft_set_pixel(game, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

// TODO: Change player drawing
void	ft_draw_minimap(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if ((int)game->playerx == j && (int)game->playery == i)
				ft_draw_square(game, (j * MAP_WIDTH) + 4, (i * MAP_HEIGHT) + 4, C_BLUE);
			else if (game->map[i][j] == '0')
				ft_draw_square(game, (j * MAP_WIDTH) + 4, (i * MAP_HEIGHT) + 4, C_WHITE);
			else if (game->map[i][j] == '1')
				ft_draw_square(game, (j * MAP_WIDTH) + 4, (i * MAP_HEIGHT) + 4, C_BLACK);
			else if (ft_strchr(PLAYER, game->map[i][j]))
				ft_draw_square(game, (j * MAP_WIDTH) + 4, (i * MAP_HEIGHT) + 4, C_WHITE);
			else if (game->map[i][j] == 'D' && ft_get_door_state(game->door, j, i, game->nbr_doors) == 1)
				ft_draw_square(game, (j * MAP_WIDTH) + 4, (i * MAP_HEIGHT) + 4, C_RED);
			else if (game->map[i][j] == 'D')
				ft_draw_square(game, (j * MAP_WIDTH) + 4, (i * MAP_HEIGHT) + 4, C_GREEN);
			j++;
		}
		i++;
	}
}
