/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:26:01 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/06 17:41:53 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
#define CUB3D

#include "../libft/libft.h"
#include "get_next_line.h"
#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"

#include <math.h>
#define PI 3.1415926535

// Windown size 1280x720
#define W_WIDTH 1280
#define W_HEIGHT 720

// Texture sizes
#define WIDTH 32
#define HEIGHT 32

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
}			t_texture;

typedef struct s_data
{
	t_list		*map_file;
	char		**map;
	char		*file_path;
	void		*mlx;
	void		*mlx_window;
	int			map_width;
	int			map_height;
	int			playerx;
	int			playery;
	int			playerdx;
	int			playerdy;
	int			player_gridx;
	int			player_gridy;
	int			player_startx;
	int			player_starty;
	double		player_angle;
	t_texture	textures;
}	t_data;

//main.c


//read_map.c


//init.c
void	ft_init(t_data *gameinfo);	// Initialize struct

//draw.c
void	ft_draw_player(t_data *gameinfo, int x, int y, int color);	//Draws player on top of map
void	ft_draw_minimap(t_data *gameinfo);	//Draws minimap
void	ft_draw_square(t_data *gameinfo, int x, int y, int color);	//Draw a square starting at x y

//player_position.c
void	ft_check_collisions(char **map, int x, int y, t_data *gameinfo); // Checks for collision with walls and adjusts player position to stop
void	ft_get_player_position(t_data *gameinfo);	// Gets player position and offsets to center of square

//keys.c
int	keys(int key, t_data *gameinfo); //Events for key press
int	x_button(t_data *gameinfo); //Exit clicking on x
#endif
