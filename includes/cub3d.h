/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:26:01 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/29 15:48:24 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "./get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <math.h>

// Windown size 1280x720
# define W_WIDTH 1280
# define W_HEIGHT 720

// Texture sizes
# define WIDTH 64
# define HEIGHT 64

# define TEXTUREW 64
# define TEXTUREH 64

// Minimap size
# define MAP_WIDTH 8
# define MAP_HEIGHT 8

# define VALID_CHARS " 01NSWE"
# define FLOOR_CHARS "01NSWE"
# define PLAYER "NSWE"

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
	t_wall	*wall;
	int		nbr_txt;
}			t_texture;

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
	t_list		*map_file;
	char		**map;
	char		**map_dup;
	char		*file_path;
	int			map_width;
	int			map_height;
	t_texture	textures;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			mapx;
	int			mapy;
	int			color;
	int			floorcolor;
	int			ceilingcolor;
	int			*texture;
	int			*texture_test;
	int			texx;
	int			imagex;
	int			imagey;
	int			main_w;
	int			main_h;
	int			bpp;
	int			line_length;
	int			endian;
	char		*path[4];
	char		*main_addr;
	void		*mlx;
	void		*mlx_window;
	void		*mlx_main;
	void		*img_n;
	void		*img_s;
	void		*img_e;
	void		*img_w;
	double		step;
	double		texpos;
	double		playerx;
	double		playery;
	double		inidirx;
	double		inidiry;
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
	double		lineh;
	double		wallx;
	t_image		image[4];
}	t_data;

// DEBUG // TMP
void	ft_map_print(char **map);
void	ft_file_print(t_list *file);
void	ft_textures_print(t_texture texture);

// Map Check Utils
void	ft_check_file_ext(char *file, t_data *gameinfo);
int		ft_valid_chars(char **map, char *set);
char	**ft_copy_map(char **map, int height);
int		ft_isflood_line(char *line);

// Map Check
void	ft_check_pos(char *set, int x, int y, t_data *gameinfo);
int		check_floors(char *set, int x, int y, t_data *gameinfo);
void	ft_check_player(t_data *gameinfo, char **map);
void	ft_check_map(char **map, int height, t_data *game);

// Read Map
void	ft_map_size(t_data *gameinfo);
void	ft_read_file(char *filepath, t_data *gameinfo);
void	ft_read_map(t_list *file, t_data *gameinfo);
void	ft_get_map(t_data *gameinfo, int start);

// Texture Check Utils
int		ft_isempty_line(char *line);
int		ft_isallnumeric(char *rgb);
int		ft_skip_line(char *line, t_data *gameinfo);
int		ft_create_rgb(char **rgb, t_data *gameinfo);

// Texture Check
int		ft_check_textures(char *line);
void	ft_get_textures(char *line, t_texture *textures, t_data *gameinfo);
char	*ft_extract_texture(char *line, t_data *gameinfo, t_wall *wall);
int		ft_get_colors(char *line, t_data *gameinfo, int surface);
char	**ft_validate_colors(char *line, t_data *gameinfo);

//init.c
void	ft_start(t_data *gameinfo);
void	ft_init(t_data *gameinfo);

//keys.c
int		keys(int key, t_data *gameinfo);
int		x_button(t_data *gameinfo);
void	moves(int key, t_data *g);
void	move_right(t_data *g);
void	move_left(t_data *g);
void	move_w(t_data *g);
void	move_s(t_data *g);
void	move_d(t_data *g);
void	move_a(t_data *g);

//player_position.c
void	ft_get_player_position(t_data *gameinfo);

//raycast.c
void	ft_raycast(t_data *gameinfo);
void	ft_direction(t_data *g);
void	ft_height(t_data *g, int *start, int *end);
void	ft_hit(t_data *g);
void	ft_side(t_data *g);

//texture.c
void	ft_load_texture(t_data *g);
void	ft_texture(t_data *gameinfo);
void	ft_set_pixel(t_data *gameinfo, int x, int y, int color);
void	ft_texture_side(t_data *g);
void	ft_texposition(t_data *g, int start, int end, int x);
void	ft_texture_put(t_data *g, int start, int end, int x);

#endif
