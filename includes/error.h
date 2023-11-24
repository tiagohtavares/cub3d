/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:46:56 by heda-sil          #+#    #+#             */
/*   Updated: 2023/11/24 16:09:12 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "./cub3d.h"

# define ERROR_USE "ERROR: Iconrrect program usage.\n"

void	error(char *msg, t_data *prog, int exit_code);
void	terminate_prog(t_data *prog, int exit_code);
#endif
