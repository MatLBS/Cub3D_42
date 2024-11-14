/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:27:01 by matle-br          #+#    #+#             */
/*   Updated: 2024/11/07 14:21:43 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	generate_background(t_img *img, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->height)
	{
		y = 0;
		while (y < data->width)
		{
			if (x < data->height / 2)
				my_mlx_pixel_put(img, y, x, data->map->c);
			else
				my_mlx_pixel_put(img, y, x, data->map->f);
			y++;
		}
		x++;
	}
}

void	create_img(t_img *img, t_data *data, char *pathfile)
{
	if (!pathfile)
		img->img = mlx_new_image(data->mlx, data->width, data->height);
	else
		img->img = mlx_xpm_file_to_image(data->mlx, pathfile, \
			&img->width, &img->height);
	if (!img->img)
	{
		printf("Error while loading an image.\n");
		c_handler(data);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
		&img->line_length, &img->endian);
	if (!img->addr)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		ft_free_data(data);
		exit(EXIT_FAILURE);
	}
}

static void	create_imgs_2(t_data *data)
{
	create_img(&data->tab_img[FRAME_K_1], data, \
		"textures/horror/frame1_knife.xpm");
	create_img(&data->tab_img[FRAME_K_2], data, \
		"textures/horror/frame2_knife.xpm");
	create_img(&data->tab_img[FRAME_K_3], data, \
		"textures/horror/frame3_knife.xpm");
	create_img(&data->tab_img[FRAME_K_4], data, \
		"textures/horror/frame4_knife.xpm");
	create_img(&data->tab_img[FRAME_K_5], data, \
		"textures/horror/frame5_knife.xpm");
	generate_background(&data->tab_img[BACKGROUND], data);
}

void	create_imgs(t_data *data, char **av)
{
	create_img(&data->tab_img[BACKGROUND], data, NULL);
	create_img(&data->tab_img[NORTH], data, data->map->no);
	create_img(&data->tab_img[SOUTH], data, data->map->so);
	create_img(&data->tab_img[EAST], data, data->map->ea);
	create_img(&data->tab_img[WEST], data, data->map->we);
	if (strcmp(av[1], "maps/horde_zombie.cub") == 0 || strcmp(av[1], \
		"maps/mapgpt.cub") == 0 || strcmp(av[1], "maps/giant_map.cub") == 0)
		create_img(&data->tab_img[DOOR], data, "textures/horror/door.xpm");
	else
		create_img(&data->tab_img[DOOR], data, "textures/wolfenstein/door.xpm");
	create_img(&data->tab_img[DOOR_1], data, "textures/horror/other_door.xpm");
	create_img(&data->tab_img[FRAME_1], data, "textures/horror/frame1.xpm");
	create_img(&data->tab_img[FRAME_2], data, "textures/horror/frame2.xpm");
	create_img(&data->tab_img[FRAME_3], data, "textures/horror/frame3.xpm");
	create_img(&data->tab_img[FRAME_4], data, "textures/horror/frame4.xpm");
	create_img(&data->tab_img[FRAME_5], data, "textures/horror/frame5.xpm");
	create_img(&data->tab_img[FRAME_6], data, "textures/horror/frame6.xpm");
	create_imgs_2(data);
}
