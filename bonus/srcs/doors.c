/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:13:01 by heda-sil          #+#    #+#             */
/*   Updated: 2023/11/30 14:49:46 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_count_doors(char **map)
{
	int	i;
	int	j;
	int	nbr_doors;

	nbr_doors = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'D')
			{
				nbr_doors++;
			}
			j++;
		}
		i++;
	}
	return (nbr_doors);
}

int	ft_get_door_state(t_door *door, int x, int y, int nbr_doors)
{
	int	i;

	i = 0;
	while (i < nbr_doors)
	{
		if (door[i].x == x && door[i].y == y)
		{
			return (door[i].state);
		}
		i++;
	}
	return (-1);
}

t_door	*ft_set_doors(t_door *doors, int nbr_doors, char **map)
{
	int	i;
	int	j;
	int	k;

	doors = ft_calloc(nbr_doors, sizeof(*doors));
	k = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'D')
			{
				doors[k].x = j;
				doors[k].y = i;
				doors[k].state = 1;
				k++;
			}
			j++;
		}
		i++;
	}
	return (doors);
}
