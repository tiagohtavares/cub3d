/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:26:01 by ttavares          #+#    #+#             */
/*   Updated: 2023/10/30 16:54:40 by ttavares         ###   ########.fr       */
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

typedef struct s_data
{
	char	**map;
	void	*mlx;
	void	*mlx_window;
	int		map_sizex;
	int		map_sizey;
	int		playerx;
	int		playery;
	int		playerdx;
	int		playerdy;
	double	playera;
}	t_data;

//main.c


//read_map.c
void	ft_map_size(t_data *gameinfo);	//Gets map size
void	ft_map_print(char **map);	//Prints the map
char	**ft_read_map(char *filepath, char **map);	//Reads the map and returns a pointer to it

//init.c
void	ft_init(t_data *gameinfo);	// Initialize struct

//draw.c
void	ft_draw_player(t_data *gameinfo, int x, int y, int color);	//Draws player on top of map
void	ft_draw_minimap(t_data *gameinfo);	//Draws minimap
void	ft_draw_square(t_data *gameinfo, int x, int y, int color);	//Draw a square starting at x y

//player_position.c
void	ft_get_player_position(t_data *gameinfo);	// Gets player position and offsets to center of square

//keys.c
int	keys(int key, t_data *gameinfo); //Events for key press
int	x_button(t_data *gameinfo); //Exit clicking on x
#endif
