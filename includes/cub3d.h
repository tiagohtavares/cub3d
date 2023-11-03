/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:26:01 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/03 07:49:13 by ttavares         ###   ########.fr       */
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
#define ONED 0.0174533 // One degree in radians

//1280x720
#define W_WIDTH 1280
#define W_HEIGHT 720

#define WIDTH 64
#define HEIGHT 64

typedef struct s_data
{
	char	**map;
	char	*map_file;
	void	*mlx;
	void	*mlx_window;
	int		map_sizetotal;
	int		map_sizex;
	int		map_sizey;
	int		playerx;
	int		playery;
	int		playerdx;
	int		playerdy;
	int		player_gridx;
	int		player_gridy;
	int		player_startx;
	int		player_starty;
	double	playera;
	double	raya;
	double	rayaV;
	double	rayaH;
	double	rayfinala;
	int		rayy;
	int		rayx;
	int		rayofssetx;
	int		rayofssety;
	int		mapx;
	int		mapy;
	int		mapp;
	double	distanceH;
	double	distanceV;
	double	finaldistance;
	int		rayxH;
	int		rayyH;
	int		rayxV;
	int		rayyV;
}	t_data;

//main.c


//read_map.c
void	ft_map_size(t_data *gameinfo);	//Gets map size
void	ft_map_print(char **map);	//Prints the map
char	**ft_read_map(char *filepath, char **map);	//Reads the map and returns a pointer to it

//init.c
void	ft_init(t_data *gameinfo);	// Initialize struct

//draw.c
void	ft_draw_player(t_data *gameinfo, int x, int y, int color, int size);	//Draws player on top of map
void	ft_draw_minimap(t_data *gameinfo);	//Draws minimap
void	ft_draw_square(t_data *gameinfo, int x, int y, int color);	//Draw a square starting at x y
void	ft_draw3d(t_data *gameinfo, int r);
void	ft_clear(t_data *gameinfo);

//player_position.c
void	ft_check_collisions(char **map, int x, int y, t_data *gameinfo); // Checks for collision with walls and adjusts player position to stop
void	ft_get_player_position(t_data *gameinfo);	// Gets player position and offsets to center of square

//keys.c
int	keys(int key, t_data *gameinfo); //Events for key press
int	x_button(t_data *gameinfo); //Exit clicking on x

//raycast.c
void	ft_raycast(t_data *gameinfo); // Raycast Loop
void	ft_raycast_horizontal(t_data *gameinfo); // Check colisions horizontal line
void	ft_raycast_vertical(t_data *gameinfo); // Check colisions vertical line

//line.c
void	ft_line(t_data *gameinfo, int x1, int y1, int x2, int y2); // Draw pixels between 2 points
double	ft_distance(double x1, double y1, double x2, double y2); // Distance between 2 points

#endif
