/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:06:12 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/24 11:20:52 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_player_pos_y(t_data *g, int j, int i)
{
	if (g->map[i][j] == 'N')
	{
		g->playerx = j + 0.5;
		g->playery = i + 0.5;
		g->inidirx = 0;
		g->inidiry = -1;
		g->planex = 1;
		g->planey = 0;
	}
	else if (g->map[i][j] == 'S')
	{
		g->playerx = j + 0.5;
		g->playery = i + 0.5;
		g->inidirx = 0;
		g->inidiry = 1;
		g->planex = -1;
		g->planey = 0;
	}
}

void	ft_player_pos_x(t_data *g, int j, int i)
{
	if (g->map[i][j] == 'E')
	{
		g->playerx = j + 0.5;
		g->playery = i + 0.5;
		g->inidirx = 1;
		g->inidiry = 0;
		g->planex = 0;
		g->planey = 1;
	}
	else if (g->map[i][j] == 'W')
	{
		g->playerx = j + 0.5;
		g->playery = i + 0.5;
		g->inidirx = -1;
		g->inidiry = 0;
		g->planex = 0;
		g->planey = -1;
	}
}

void	ft_get_player_position(t_data *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			ft_player_pos_y(g, j, i);
			ft_player_pos_x(g, j, i);
			j++;
		}
		i++;
	}
}
