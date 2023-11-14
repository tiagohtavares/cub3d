/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:01:59 by heda-sil          #+#    #+#             */
/*   Updated: 2023/11/14 12:39:38 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CHECK_H
# define MAP_CHECK_H


#include "./cub3d.h"
#include "./errors.h"
#include <stdbool.h>

#include "./debug.h"

void	ft_check_file_ext(char *file, t_data *gameinfo);
void	ft_get_textures(char *line, t_texture *textures, t_data *gameinfo);
bool	ft_isempty_line(char *line);
bool	ft_check_textures(char *line);
bool	ft_skip_line(char *line, t_data *gameinfo);
int		ft_get_colors(char *line, t_data *gameinfo, int surface);
char	**ft_validate_colors(char *line, t_data *gameinfo);
char	*ft_extract_texture(char *line, t_data *gameinfo, t_wall *wall);

#endif
