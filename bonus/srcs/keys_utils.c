/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:33:53 by ttavares          #+#    #+#             */
/*   Updated: 2023/12/08 11:57:41 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/errors.h"

void	moves(int key, t_data *g)
{
	if (key == XK_w)
		move_w(g);
	else if (key == XK_s)
		move_s(g);
	else if (key == XK_a)
		move_a(g);
	else if (key == XK_d)
		move_d(g);
	else if (key == XK_Right)
		rotate(g->inidirx, g->planex, 0.1, g);
	else if (key == XK_Left)
		rotate(g->inidirx, g->planex, -0.1, g);
}

int	x_button(t_data *g)
{
	terminate_prog(g, EXIT_SUCCESS);
	return (0);
}

/* TODO: Think if we add a way to close the door automatically AND a way to
open the door slower instead of pressing the button and the door
just disappears */
void	open_door(t_data *g)
{
	int	i;

	i = 0;
	while (i < g->nbr_doors)
	{
		if (g->door[i].x == (int)(g->playerx + g->inidirx * 1.5) && \
		g->door[i].y == (int)(g->playery + g->inidiry * 1.5))
		{
			if (g->door[i].state)
				g->door[i].state = 0;
			else
				g->door[i].state = 1;
		}
		i++;
	}
}
