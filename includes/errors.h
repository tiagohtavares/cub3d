/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:46:56 by heda-sil          #+#    #+#             */
/*   Updated: 2023/11/06 16:59:48 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

#include "./cub3d.h"

#define ERR_USE "Error\nIncorrect program usage. Correct usage ./cub3d <map>.cub"
#define ERR_OPEN "Error\nFailed to open map file"
#define ERR_TYPE "Error\nIncorret file type. Map file must be a '.cub' file"
#define ERR_NL "Error\nInvalid newline in map"
#define ERR_CHAR "Error\nInvalid character in map"
#define ERR_PLAYER "Error\nInvalid number of player starting postion"
#define ERR_WALLS "Error\nMap must be surrounded by walls"
#define ERR_FORMAT "Error\nMap must be the last element of the scene"
#define ERR_TEXTMISS "Error\nMissing one or more textures"
#define ERR_TEXTINV "Error\nInvalid texture"	// Check if mlx func to convert mlx to img works, if fails, prob invalid texture file
#define ERR_TEXTINFO "Error\nInvalid texture path or color"

void	ft_error(char *msg, t_data *prog, int exit_code);
void	terminate_prog(t_data *prog, int exit_code);
void	free_wall_textures(t_texture *texture, void *mlx);
void	*ft_db_free(char **ptr);
#endif
