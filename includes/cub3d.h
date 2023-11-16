/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:26:01 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/16 11:12:34 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
#define CUB3D

#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include <math.h>

// Windown size 1280x720
#define W_WIDTH 1280
#define W_HEIGHT 720

// Texture sizes
#define WIDTH 64
#define HEIGHT 64

#define C_RED 16711680
#define C_BLUE 255
#define C_GREEN 65280
#define C_WHITE 16777215
#define C_BLACK 0

// Minimap size
#define MAP_WIDTH 8
#define MAP_HEIGHT 8

enum e_walls
{
	N,
	S,
	E,
	W
};

// Struct for wall textures, it will prob need to include mlx stuff
typedef struct s_wall
{
	char	*path;
	void	*img;
	int		width;
	int		height;
}		t_wall;

// Struct to keep track of all textures including ceiling and floor color
typedef struct s_texture
{
	t_wall	*walls;
	int		floor;
	int		ceiling;
	int		nbr_txt;
}			t_texture;

typedef struct s_data
{
	t_list		*map_file;
	char		**map;
	char		*file_path;
	void		*mlx;
	void		*mlx_window;
	double		playerx;
	double		playery;
	double		inidirx;
	double		inidiry;
	int			map_width;
	int			map_height;
	double		planex;
	double		planey;
	double		camerax;
	double		raydirx;
	double		raydiry;
	double		distancex;
	double		distancey;
	double		deltax;
	double		deltay;
	double		perpwalldistance;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			mapx;
	int			mapy;
	int			color; //REMOVE: Can be removed later will be replaced by textures (I think)
	double		lineh;
	int			playerdx;
	int			playerdy;
	int			player_gridx;
	int			player_gridy;
	int			player_startx;
	int			player_starty;
	double		player_angle;
	t_texture	textures;
}	t_data;

//read_map.c


//init.c
void	ft_start(t_data *gameinfo);
void	ft_init(t_data *gameinfo);

//keys.c
int		keys(int key, t_data *gameinfo);
int		x_button(t_data *gameinfo); //Exit clicking on x

//player_position.c
void	ft_get_player_position(t_data *gameinfo);

//raycast.c
void	ft_raycast(t_data *gameinfo);

//draw.c
void	ft_draw_vertical(t_data *gameinfo, int x, int start, int end, int color);
void	ft_clear(t_data *gameinfo);
#endif
