/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:48:45 by heda-sil          #+#    #+#             */
/*   Updated: 2023/11/29 12:05:18 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/errors.h"

void	ft_error(char *msg, t_data *prog, int exit_code)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	terminate_prog(prog, exit_code);
}

// Free char ** and returns it after setting it to NULL
void	*ft_db_free(char **ptr)
{
	int	i;

	if (!ptr)
		return (NULL);
	i = -1;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr);
	ptr = NULL;
	return (ptr);
}

void	ft_clean_walls(t_data *prog)
{
	int	i;

	i = 0;
	while (i < TEXT_NBR - 2)
	{
		if (prog->image[i].image)
			mlx_destroy_image(prog->mlx, prog->image[i].image);
		free(prog->image[i].texture);
		i++;
	}
	if (prog->textures.wall)
	{
		ft_free_wall(&prog->textures);
	}
}

// Frees all allocs and exits
void	terminate_prog(t_data *prog, int exit_code)
{
	if (prog)
	{
		ft_clean_walls(prog);
		if (prog->mlx_main)
		{
			mlx_destroy_image(prog->mlx, prog->mlx_main);
		}
		if (prog->mlx_window)
			mlx_destroy_window(prog->mlx, prog->mlx_window);
		if (prog->mlx)
		{
			mlx_destroy_display(prog->mlx);
			free(prog->mlx);
		}
		prog->map = ft_db_free(prog->map);
		free(prog->file_path);
		ft_lstclear(&prog->map_file, free);
	}
	exit(exit_code);
}

// Frees the walls and destroys the img
void	ft_free_wall(t_texture *texture)
{
	int	i;

	i = -1;
	while (++i < TEXT_NBR - 2)
	{
		free(texture->wall[i].path);
		texture->wall[i].path = NULL;
	}
	free(texture->wall);
	texture->wall = NULL;
}
