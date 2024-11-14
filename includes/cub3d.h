/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:50:09 by matle-br          #+#    #+#             */
/*   Updated: 2024/11/14 09:53:29 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/time.h>
# include <signal.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// # define WIDTH 800
// # define HEIGHT 800
// # define WIDTH_XPM 100
// # define HEIGHT_XPM 100
# define MOVE_SPEED 0.075
# define TURN_SPEED 0.05
# define SIZE_SQUARE 20
# define WIDTH_MINIMAP 300
# define HEIGHT_MINIMAP 200
# define MOUSE_SENSI 50
# define HEIGHT_STEP 700
# define WIDTH_STEP 100

# define FIRST_SENTENCE "Welcome, this is a manual on how you can play \
with the keyboard!"

# define SECOND_SENTENCE "1 -> First, use W, S, A and D to move the player."

# define THIRD_SENTENCE "2 -> Then, use the two arrows <- | -> \
to move your point of view."

# define FOURTH_SENTENCE "3 -> Press the button 'e' near a door \
to open/close it."

# define FIFTH_SENTENCE "4 -> Press 'Ctrl' to move your point of \
view with the mouse."

# define SIXTH_SENTENCE "5 -> Press again 'Ctrl' to disable this feature."

# define SEVENTH_SENTENCE "6 -> Finally, press Left Click to take out your \
knife and kill the Zombies !"

# define HEIGHT_SENTENCE "Have fun and careful to the Zombies !"

/* ----------- Définition de mes images -------------*/

# define BACKGROUND 0
# define NORTH 1
# define SOUTH 2
# define EAST 3
# define WEST 4
# define DOOR 5
# define DOOR_1 6
# define FRAME_1 7
# define FRAME_2 8
# define FRAME_3 9
# define FRAME_4 10
# define FRAME_5 11
# define FRAME_6 12
# define FRAME_K_1 13
# define FRAME_K_2 14
# define FRAME_K_3 15
# define FRAME_K_4 16
# define FRAME_K_5 17

/*---------------------------------------------------*/

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f;
	int		c;
	int		nb_params;
	char	pos_player;
	int		player;
	char	**map;
	char	**cpy_map;
}	t_map;

typedef struct s_wall
{
	double	perpwalldist;
	int		lineheight;
	int		drawstart;
	int		drawend;
	long	color;
	int		side;
	int		width_xpm;
	int		height_xpm;
	int		face;
	int		hit_door;
	int		hit_zombie;
}	t_wall;

typedef struct s_player
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	planex;
	double	planey;
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		texx;
	int		texy;
	double	wallx;
	double	texpos;
	double	step;
}	t_player;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}	t_img;

typedef struct s_keys
{
	int	key_w;
	int	key_a;
	int	key_s;
	int	key_d;
	int	left_arrow;
	int	right_arrow;
	int	mouse_press;
}	t_keys;

typedef struct s_sprites
{
	double		posx;
	double		posy;
	int			spritescreenx;
	int			spriteheight;
	int			drawstarty;
	int			drawendy;
	int			spritewidth;
	int			drawendx;
	int			drawstartx;
	int			texx;
	int			texy;
	int			stripe;
	int			spriteorder;
	double		spritex;
	double		spritey;
	double		invdet;
	double		transformx;
	double		transformy;
	double		spritedistance;
}	t_sprites;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			fd;
	char		*str;
	int			width;
	int			height;
	int			mouse;
	long		first_action;
	long		action_mouse;
	double		*zbuffer;
	int			num_sprites;
	int			hit;
	int			pid_music;
	t_player	*player;
	t_map		*map;
	t_wall		*wall;
	t_keys		*keys;
	t_sprites	*sprites;
	t_img		tab_img[18];
}	t_data;

/* events.c */
void			key_starter_2(int key, t_data *data);
int				key_starter(int key, t_data *data);
int				key_closer(int key, t_data *data);
int				check_keys(t_data *data);
void			key_starter_2(int key, t_data *data);
int				key_starter(int key, t_data *data);
int				key_closer(int key, t_data *data);
int				check_keys(t_data *data);

/* events2.c */
void			turn_left(t_data *data, double rotation_speed);
void			turn_right(t_data *data, double rotation_speed);
int				c_handler(t_data *data);
int				handle_mouse(int x, int y, t_data *data);
int				handle_button(int button, int x, int y, t_data *data);
void			turn_left(t_data *data, double rotation_speed);
void			turn_right(t_data *data, double rotation_speed);
int				c_handler(t_data *data);
int				handle_mouse(int x, int y, t_data *data);
int				handle_button(int button, int x, int y, t_data *data);

/* events3.c */
void			move_forward(t_data *data);
void			move_backwards(t_data *data);
void			move_left(t_data *data);
void			move_right(t_data *data);
int				release_button(int button, int x, int y, t_data *data);
void			move_forward(t_data *data);
void			move_backwards(t_data *data);
void			move_left(t_data *data);
void			move_right(t_data *data);
int				release_button(int button, int x, int y, t_data *data);

/* init.c */
void			init_imgs(t_img *tab_img);
t_keys			*init_keys(t_data *data);
void			init_data(t_data *data);
void			init_mlx(t_data *data);
long			get_time(void);
void			init_imgs(t_img *tab_img);
t_keys			*init_keys(t_data *data);
void			init_data(t_data *data);
void			init_mlx(t_data *data);
long			get_time(void);

/* init2.c */
t_wall			*init_wall(t_data *data);
t_map			*init_map(void);
void			init_player_2(t_player *player);
t_player		*init_player(t_data *data);
t_wall			*init_wall(t_data *data);
t_map			*init_map(void);
void			init_player_2(t_player *player);
t_player		*init_player(t_data *data);

/* free.c */
void			ft_free_cub(char **tab);
void			ft_free_images_2(t_data *data);
void			ft_free_images(t_data *data);
void			ft_free_data_2(t_data *data);
void			ft_free_data(t_data *data);
void			ft_free_cub(char **tab);
void			ft_free_images_2(t_data *data);
void			ft_free_images(t_data *data);
void			ft_free_data_2(t_data *data);
void			ft_free_data(t_data *data);

/* get_next_line.c */
char			*fill_stash(int fd, char *stash);
char			*fill_line(char *stash);
char			*clean_stash(char *stash);
char			*get_next_line(int fd, int flag);
char			*fill_stash(int fd, char *stash);
char			*fill_line(char *stash);
char			*clean_stash(char *stash);
char			*get_next_line(int fd, int flag);

/* images.c */
void			generate_background(t_img *img, t_data *data);
void			create_img(t_img *img, t_data *data, char *pathfile);
void			create_imgs(t_data *data, char **av);
void			generate_background(t_img *img, t_data *data);
void			create_img(t_img *img, t_data *data, char *pathfile);
void			create_imgs(t_data *data, char **av);

/* check_input.c */
void			remove_endl(char *str);
void			check_av1(char	**av, t_data *data);
void			parse_map(t_data *data);
void			parse_args(t_data *data);
int				check_input(char **av, t_data *data);
void			remove_endl(char *str);
void			check_av1(char	**av, t_data *data);
void			parse_map(t_data *data);
void			parse_args(t_data *data);
int				check_input(char **av, t_data *data);

/* check_map.c */
int				check_space(t_data *data, char **tab, int i, int j);
int				check_line(char *str, t_data *data, int y, int i);
int				check_first_line(char **tab, t_data *data, int i, int j);
int				check_last_line(char **tab, t_data *data, int i);
int				check_map(t_data *data);
int				check_space(t_data *data, char **tab, int i, int j);
int				check_line(char *str, t_data *data, int y, int i);
int				check_first_line(char **tab, t_data *data, int i, int j);
int				check_last_line(char **tab, t_data *data, int i);
int				check_map(t_data *data);

/* parsing_utils.c */
int				ft_isspace(char *str);
char			*check_xpm(t_data *data, int i);
int				check_whitespace(char *str);
int				check_rgb_suite(char **tab, t_data *data, char *new_str, int i);
int				check_rgb(t_data *data, int i);
int				ft_isspace(char *str);
char			*check_xpm(t_data *data, int i);
int				check_whitespace(char *str);
int				check_rgb_suite(char **tab, t_data *data, char *new_str, int i);
int				check_rgb(t_data *data, int i);

/* parsing_utils2.c */
void			ft_strcpy_cub(char *dest, char *src, int size, int j);
void			*ft_realloc(void *ptr, size_t old_size, size_t new_size);
int				check_number(char *str);
int				check_sides(char *str, t_data *data);
void			handle_sprites(t_data *data, int y, int i);
void			ft_strcpy_cub(char *dest, char *src, int size, int j);
void			*ft_realloc(void *ptr, size_t old_size, size_t new_size);
int				check_number(char *str);
int				check_sides(char *str, t_data *data);
void			handle_sprites(t_data *data, int y, int i);

/* parsing_utils3.c */
int				check_no_xpm(t_data *data, int start);
int				check_no_rgb(t_data *data, int start);
void			fill_map(t_data *data, int i, int nb, int len);
int				check_no_xpm(t_data *data, int start);
int				check_no_rgb(t_data *data, int start);
void			fill_map(t_data *data, int i, int nb, int len);

/* raycasting.c */
void			algo_dda_suite_suite(t_data *data);
void			algo_dda_suite(t_data *data);
void			algo_dda(t_data *data);
void			launch_rays(t_data *data);
void			raycasting(t_data *data, long nb);
void			algo_dda_suite_suite(t_data *data);
void			algo_dda_suite(t_data *data);
void			algo_dda(t_data *data);
void			launch_rays(t_data *data);
void			raycasting(t_data *data, long nb);

/* minimap.c */
void			find_pixel(t_data *data, int x, int y);
void			create_minimap(t_data *data);
void			find_pixel(t_data *data, int x, int y);
void			create_minimap(t_data *data);

/* sprites.c */
void			sort_sprites(t_data *data, int i);
void			create_sprites4(t_data *data, int nb, int y);
void			create_sprites3(t_data *data, int nb, int y);
void			create_sprites2(t_data *data, int nb);
void			create_sprites(t_data *data, int x);
void			sort_sprites(t_data *data, int i);
void			create_sprites4(t_data *data, int nb, int y);
void			create_sprites3(t_data *data, int nb, int y);
void			create_sprites2(t_data *data, int nb);
void			create_sprites(t_data *data, int x);

/* sprites2.c */
int				move_knife(t_data *data, int x, int y);
int				move_knife_2(t_data *data, int nb);
int				move_knife(t_data *data, int x, int y);
int				move_knife_2(t_data *data, int nb);

/* raycasting_utils.c */
int				size_tab(char **tab);
void			which_fov(t_data *data);
void			which_position(t_data *data);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			my_mlx_pixel_put_data(t_data *data, int x, int y, int color);
int				size_tab(char **tab);
void			which_fov(t_data *data);
void			which_position(t_data *data);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			my_mlx_pixel_put_data(t_data *data, int x, int y, int color);

/* raycasting_utils2.c */
unsigned long	get_pixel_color(t_img *img, int pixelX, \
	int pixelY, t_data *data);
void			get_texture_color_suite(t_data *data, int pixelX, int y);
void			get_texture_color(t_data *data, int pixelX, int y);
void			display_wall(t_data *data, int x);

#endif
