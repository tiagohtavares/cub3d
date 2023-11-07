/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:01:59 by heda-sil          #+#    #+#             */
/*   Updated: 2023/11/07 12:10:11 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CHECK_H
# define MAP_CHECK_H


#include "./cub3d.h"
#include "./errors.h"
#include <stdbool.h>

#include "./debug.h"

void	ft_check_file_ext(char *file, t_data *gameinfo);
void	ft_get_textures(char *line, t_texture *textures);
bool	ft_isempty_line(char *line);
bool	ft_check_textures(char *line);
bool	ft_skip_line(char *line, t_data *gameinfo);

#endif
