/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:26:01 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/22 16:32:11 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../libft/libft.h"
#include "get_next_line.h"
#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include <math.h>

#define W_WIDTH 1800
#define W_HEIGHT 900

#define WIDTH 64
#define HEIGHT 64

#define TEXTUREW 64
#define TEXTUREH 64

#define C_RED 16711680
#define C_BLUE 255
#define C_GREEN 65280
#define C_WHITE 16777215
#define C_BLACK 0

typedef struct s_image
{
	void	*image;
	char	*addr;
	int		x;
	int		y;
	int		bpp;
	int		line_length;
	int		endian;
	int		*texture;
}	t_image;


typedef struct s_data
{
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		mapx;
	int		mapy;
	int		color;
	int		floorcolor;
	int		ceilingcolor;
	int		*texture;
	int		*texture_test;
	int		texX;
	int		imagex;
	int		imagey;
	int		main_w;
	int		main_h;
	int		bpp;
	int		line_length;
	int		endian;
	char	*path[4];
	char	**map;
	char	*map_file;
	char	*main_addr;
	void	*mlx;
	void	*mlx_window;
	void	*mlx_main;
	void	*img_n;
	void	*img_s;
	void	*img_e;
	void	*img_w;
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
	double	lineh;
	double	wallx;
	t_image		image[4];
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

//texture.c
void	ft_texture(t_data *gameinfo);
void	ft_set_pixel(t_data *gameinfo, int x, int y, int color);

#endif
