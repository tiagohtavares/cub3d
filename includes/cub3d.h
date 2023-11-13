/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:26:01 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/13 16:05:35 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
#define CUB3D

#include "../libft/libft.h"
#include "get_next_line.h"
#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include <math.h>

#define W_WIDTH 1080
#define W_HEIGHT 720

#define WIDTH 64
#define HEIGHT 64

#define C_RED 16711680
#define C_BLUE 255
#define C_GREEN 65280
#define C_WHITE 16777215
#define C_BLACK 0

typedef struct s_data
{
	char	**map;
	char	*map_file;
	void	*mlx;
	void	*mlx_window;
	double	playerx;
	double	playery;
	double	inidirx;
	double	inidiry;
	double	planex;
	double	planey;
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	distancex;
	double	distancey;
	double	deltax;
	double	deltay;
	double	perpwalldistance;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		mapx;
	int		mapy;
	int		color;
	double	lineh;
}	t_data;

//read_map.c
char	**ft_read_map(char *filepath, char **map);

//init.c
void	ft_start(t_data *gameinfo);
void	ft_init(t_data *gameinfo);

//keys.c
int	keys(int key, t_data *gameinfo);
int	x_button(t_data *gameinfo); //Exit clicking on x

//player_position.c
void	ft_get_player_position(t_data *gameinfo);

//raycast.c
void	ft_raycast(t_data *gameinfo);

//draw.c
void	ft_draw_vertical(t_data *gameinfo, int x, int start, int end, int color);
void	ft_clear(t_data *gameinfo);
#endif
