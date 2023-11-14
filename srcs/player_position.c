/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:06:12 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/14 11:22:20 by heda-sil         ###   ########.fr       */
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
			}
			j++;
		}
		i++;
	}
}
