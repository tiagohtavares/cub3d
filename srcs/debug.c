/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:01:06 by heda-sil          #+#    #+#             */
/*   Updated: 2023/11/14 12:19:45 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//Prints the map
void	ft_map_print(char **map)
{
	int	i;

	ft_printf("\n\n----------MAP ARRAY---------\n");
	i = 0;
	while(map[i])
	{
		ft_printf("%s\n",map[i]);
		i++;
	}
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
	ft_printf("NO: %s\n", texture.walls[N].path);
	ft_printf("SO: %s\n", texture.walls[S].path);
	ft_printf("EA: %s\n", texture.walls[E].path);
	ft_printf("WE: %s\n", texture.walls[W].path);
	ft_printf("F: %X\n", texture.floor);
	ft_printf("C: %X\n", texture.ceiling);
	ft_printf("----------END----------\n\n");
}
