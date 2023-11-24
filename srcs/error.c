/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:48:45 by heda-sil          #+#    #+#             */
/*   Updated: 2023/11/24 11:22:21 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/error.h"
#include <stdio.h>

void	error(char *msg, t_data *prog, int exit_code)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	terminate_prog(prog, exit_code);
}

void	*ft_db_free(char **ptr)
{
	int	i;

	i = -1;
	while (ptr[++i])
	{
		free(ptr[i]);
	}
	free(ptr);
	ptr = NULL;
	return (ptr);
}

void	terminate_prog(t_data *prog, int exit_code)
{
	if (prog)
	{
		if (prog->mlx_window)
		{
			mlx_destroy_window(prog->mlx, prog->mlx_window);
		}
		if (prog->mlx)
		{
			mlx_destroy_display(prog->mlx);
			free(prog->mlx);
		}
		if (prog->map)
		{
			prog->map = ft_db_free(prog->map);
		}
		if (prog->map_file)
		{
			free(prog->map_file);
		}
	}
	exit(exit_code);
}
