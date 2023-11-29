/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:29:20 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/29 11:47:22 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_texture_put(t_data *g, int start, int end, int x)
{
	int	f;
	int	c;

	f = 0;
	c = end;
	while (f < start)
	{
		ft_set_pixel(g, x, f, g->ceilingcolor);
		f++;
	}
	while (c < W_HEIGHT - 1)
	{
		ft_set_pixel(g, x, c, g->floorcolor);
		c++;
	}
	ft_texposition(g, start, end, x);
}

void	ft_texposition(t_data *g, int start, int end, int x)
{
	int	texy;
	int	color;
	int	y;

	g->texx = (int)(g->wallx * (double)g->imagex);
	g->step = 1.0 * g->imagey / g->lineh;
	g->texpos = (start - W_HEIGHT / 2 + g->lineh / 2) * g->step;
	y = start;
	while (y < end)
	{
		texy = (int)g->texpos & (g->imagey - 1);
		g->texpos += g->step;
		color = g->texture[g->imagey * texy + g->texx];
		ft_set_pixel(g, x, y, color);
		y++;
	}
}

void	ft_texture_side_n(t_data *g)
{
	if (g->map[g->mapy][g->mapx] == '1')
	{
		if (g->raydiry < 0)
		{
			g->texture = g->image[0].texture;
			g->imagex = g->image[0].x;
			g->imagey = g->image[0].y;
		}
		else
		{
			g->texture = g->image[2].texture;
			g->imagex = g->image[2].x;
			g->imagey = g->image[2].y;
		}
	}
	else // TMP is a door
	{
		g->texture = g->image[4].texture;
		g->imagex = g->image[4].x;
		g->imagey = g->image[4].y;
	}
}

void	ft_texture_side_s(t_data *g)
{
	if (g->map[g->mapy][g->mapx] == '1')
	{
		if (g->raydirx < 0)
		{
			g->texture = g->image[3].texture;
			g->imagex = g->image[3].x;
			g->imagey = g->image[3].y;
		}
		else
		{
			g->texture = g->image[1].texture;
			g->imagex = g->image[1].x;
			g->imagey = g->image[1].y;
		}
	}
	else // TMP - is a door
	{
		g->texture = g->image[4].texture;
		g->imagex = g->image[4].x;
		g->imagey = g->image[4].y;
	}
}

void	ft_texture_side(t_data *g)
{
	if (g->side == 1)
	{
		ft_texture_side_n(g);
	}
	else
	{
		ft_texture_side_s(g);
	}
}
