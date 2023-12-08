/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:13:01 by heda-sil          #+#    #+#             */
/*   Updated: 2023/12/08 11:24:02 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Returns the number of doors
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
				nbr_doors++;
			j++;
		}
		i++;
	}
	return (nbr_doors);
}

// Returns the state of a given door specified by xy coord
int	ft_get_door_state(t_door *door, int x, int y, int nbr_doors)
{
	int	i;

	i = 0;
	while (i < nbr_doors)
	{
		if (door[i].x == x && door[i].y == y)
			return (door[i].state);
		i++;
	}
	return (-1);
}

// Sets the state of a given door specified by x, y coords
void	ft_set_door_state(t_data *g, int x, int y, int value)
{
	int	i;

	i = 0;
	while (i < g->nbr_doors)
	{
		if (g->door[i].x == x && g->door[i].y == y)
		{
			g->door[i].state = value;
			break ;
		}
		i++;
	}
}

// Creates a door array
t_door	*ft_create_doors(t_door *doors, int nbr_doors, char **map)
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
