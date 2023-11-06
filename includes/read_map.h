/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:40:58 by heda-sil          #+#    #+#             */
/*   Updated: 2023/11/06 17:46:42 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_MAP_H
# define READ_MAP_H

#include "./cub3d.h"
#include "./errors.h"
#include "./map_check.h"


void	ft_map_size(t_data *gameinfo);
void	ft_read_file(char *filepath, t_data *gameinfo);
void	ft_read_map(t_list *file, t_data *gameinfo);
void	ft_get_map(t_data *gameinfo, int start);

#endif
