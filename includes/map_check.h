/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:01:59 by heda-sil          #+#    #+#             */
/*   Updated: 2023/11/03 16:04:15 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CHECK_H
# define MAP_CHECK_H

#include "../includes/cub3d.h"
#include "../includes/errors.h"
#include <stdbool.h>


void	ft_check_file_ext(char *file, t_data *gameinfo);
void	ft_get_textures(char *line, t_texture *textures);
bool	ft_isempty_line(char *line);
bool	ft_check_textures(char *line);
bool	ft_skip_line(int fd, char *line, t_data *gameinfo, int mid_map);

#endif
