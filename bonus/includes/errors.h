/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:46:56 by heda-sil          #+#    #+#             */
/*   Updated: 2023/12/08 12:37:11 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "./cub3d.h"

# define ERR_USE "Error\nIncorrect program usage. Correct usage ./cub3d \
<map>.cub"
# define ERR_OPEN "Error\nFailed to open map file"
# define ERR_CLOSE "Error\nFailed to close map file"
# define ERR_SCENE "Error\nInvalid scene"
# define ERR_TYPE "Error\nIncorret file type. Map file must be a '.cub' file"
# define ERR_NL "Error\nInvalid newline in map"
# define ERR_CHAR "Error\nInvalid character in map"
# define ERR_PLAYER "Error\nInvalid number of player starting postion"
# define ERR_MAP "Error\nInvalid map formatting"
# define ERR_WALLS "Error\nMap must be surrounded by walls"
# define ERR_FORMAT "Error\nMap must be the last element of the scene"
# define ERR_TEXTMISS "Error\nInvalid or missing textures or the map is not the \
last element of the scene"
# define ERR_TEXTINFO "Error\nInvalid or missing texture path or color value"
# define ERR_TEXTDUP "Error\nDuplicated texture"
# define ERR_TEXT "Error\nInvalid texture file. Textures should be a valid xpm \
file"
# define ERR_DOOR "Error\nInvalid door. Doors must be inbetween two opposing \
walls"

void	ft_error(char *msg, t_data *prog, int exit_code);
void	terminate_prog(t_data *prog, int exit_code);
void	ft_free_wall(t_texture *texture);
void	*ft_db_free(char **ptr);
#endif
