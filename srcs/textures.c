/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:39:15 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/20 18:53:43 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_texture(t_data *gameinfo)
{
	for(int x = 0; x < TEXTUREW; x++)
	{
		for(int y = 0; y < TEXTUREH; y++)
		{
			int xorcolor = (x * 256 / TEXTUREH) ^ (y * 256 / TEXTUREW);
			int xycolor = y * 128 / TEXTUREW + x * 128 / TEXTUREH;
			gameinfo->textureN[TEXTUREW * y + x] = 65536 * 254 * (x != y && x != TEXTUREW - y); //flat red texture with black cross
			gameinfo->textureS[TEXTUREW * y + x] = 256 * xorcolor; //xor green
			gameinfo->textureE[TEXTUREW * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
			gameinfo->textureW[TEXTUREW * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
		}
	}
}
