/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:03:37 by heda-sil          #+#    #+#             */
/*   Updated: 2023/11/14 12:17:06 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

#include "cub3d.h"

void	ft_map_print(char **map);
void	ft_file_print(t_list *file);
void	ft_textures_print(t_texture texture);

#endif
