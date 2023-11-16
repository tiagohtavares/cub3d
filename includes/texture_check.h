/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_check.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:01:59 by heda-sil          #+#    #+#             */
/*   Updated: 2023/11/16 11:21:00 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_CHECK_H
# define TEXTURE_CHECK_H

#include "./cub3d.h"
#include "./errors.h"

#include "./debug.h"

void	ft_check_file_ext(char *file, t_data *gameinfo);
void	ft_get_textures(char *line, t_texture *textures, t_data *gameinfo);
int		ft_check_textures(char *line);
int		ft_get_colors(char *line, t_data *gameinfo, int surface);
char	**ft_validate_colors(char *line, t_data *gameinfo);
char	*ft_extract_texture(char *line, t_data *gameinfo, t_wall *wall);

// Utils
int		ft_isallnumeric(char *rgb);
int		ft_isempty_line(char *line);
int		ft_skip_line(char *line, t_data *gameinfo);
int		ft_create_rgb(char **rgb, t_data *gameinfo);
#endif
