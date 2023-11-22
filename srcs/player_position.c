/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:06:12 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/22 17:26:37 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
				gameinfo->playerx = j + 0.5;
				gameinfo->playery = i + 0.5;
				gameinfo->inidirx = 0;
				gameinfo->inidiry = -1;
				gameinfo->planex = 1;
				gameinfo->planey = 0;
			}
			else if(gameinfo->map[i][j] == 'S')
			{
				gameinfo->playerx = j + 0.5;
				gameinfo->playery = i + 0.5;
				gameinfo->inidirx = 0;
				gameinfo->inidiry = 1;
				gameinfo->planex = -1;
				gameinfo->planey = 0;
			}
			else if(gameinfo->map[i][j] == 'E')
			{
				gameinfo->playerx = j + 0.5;
				gameinfo->playery = i + 0.5;
				gameinfo->inidirx = 1;
				gameinfo->inidiry = 0;
				gameinfo->planex = 0;
				gameinfo->planey = 1;
			}
			else if(gameinfo->map[i][j] == 'W')
			{
				gameinfo->playerx = j + 0.5;
				gameinfo->playery = i + 0.5;
				gameinfo->inidirx = -1;
				gameinfo->inidiry = 0;
				gameinfo->planex = 0;
				gameinfo->planey = -1;
			}
			j++;
		}
		i++;
	}
}
