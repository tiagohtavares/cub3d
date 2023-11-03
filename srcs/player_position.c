/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:06:12 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/03 04:47:10 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
			}
			j++;
		}
		i++;
	}
}
