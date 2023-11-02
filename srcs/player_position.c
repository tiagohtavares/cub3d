/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:06:12 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/02 14:17:37 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// // Checks for collision with walls and adjusts player position to stop
// void	ft_check_collisions(char **map, int x, int y, t_data *gameinfo)
// {
// 	if (x > 0 && x < gameinfo->map_sizex && y > 0 && y < gameinfo->map_sizey && (map[y][x] == 1 || map[y][x + 1] == 1 || map[y][x - 1] == 1)) //inside wall
// 	{
// 		gameinfo->playerdx = 0;
// 		gameinfo->playerdy = 0;
// 	}
// 	if (x > 0 && x < gameinfo->map_sizex && y > 0 && y < gameinfo->map_sizey && (map[y][x] == 1 || map[y + 1][x] == 1 || map[y - 1][x] == 1)) //inside wall
// 	{
// 		gameinfo->playerdx = 0;
// 		gameinfo->playerdy = 0;
// 	}

// }

// Gets player position and offsets to center of square
void	ft_get_player_position(t_data *gameinfo)
{
	int	i;
	int	j;

	i = 0;
	while(gameinfo->map[i])
	{
		j = 0;
		while(gameinfo->map[i][j])
		{
			if(gameinfo->map[i][j] == 'N')
			{
				gameinfo->player_gridx = j;
				gameinfo->player_gridy = i;
				gameinfo->playerx = j * WIDTH + WIDTH / 2;
				gameinfo->playery = i * HEIGHT + HEIGHT / 2;
				gameinfo->player_startx = gameinfo->playerx;
				gameinfo->player_starty = gameinfo->playery;
				printf("INITAL Px: %d\t|\tINITIAL Py: %d\n", gameinfo->playerx, gameinfo->playery);
				printf("INITAL Gx: %d\t|\tINITIAL Gy: %d\n", gameinfo->player_gridx, gameinfo->player_gridy);
			}
			j++;
		}
		i++;
	}
}
