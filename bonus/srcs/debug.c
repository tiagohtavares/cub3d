/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:01:06 by heda-sil          #+#    #+#             */
/*   Updated: 2023/12/19 13:09:51 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// TMP: move to header file

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

/* // TODO: change the values to draw the orientation
void	ft_draw_player(t_data *game, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < MAP_WIDTH)
	{
		j = -1;
		while (++j < MAP_HEIGHT)
			ft_set_pixel(game, x + i, y + j, C_BLUE);
	}
//	if (game->side == 1 && game->raydiry < 0)
//		printf("NORTH\n");
//	else if (game->side == 1 && game->raydiry >= 0)
//		printf("SOUTH\n");
//	else if (game->side != 1 && game->raydirx < 0)
//		printf("WEST\n");
//	else if (game->side != 1 && game->raydirx >= 0)
//		printf("EAST\n");
//	ft_draw_indicator(game, x, y);
} */

/*
// TODO: Refactor to remove hardcoded values; FIX: logic to draw all cases, find a way to draw diagonalls
void	ft_draw_indicator(t_data *game, int x, int y)
{
	int	i;
	int	j;

	i = 1;
	while (++i < 5)
	{
		j = 7;
		while (++j < 8 + 6)
			ft_set_pixel(game, x + i, y + j, C_RED);
	}
}
*/
