/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 23:27:53 by matle-br          #+#    #+#             */
/*   Updated: 2024/11/05 16:04:04 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	start_music(void)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		freopen("/dev/null", "w", stdout);
		freopen("/dev/null", "w", stderr);
		execlp("ffplay", "ffplay", "-nodisp", \
		"-autoexit", "opening_twd.mp3", NULL);
		exit(1);
	}
	return (pid);
}

void	handle_events(t_data *data)
{
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, c_handler, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, key_starter, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, key_closer, data);
	mlx_hook(data->win, ButtonPress, ButtonPressMask, handle_button, data);
	mlx_hook(data->win, ButtonRelease, ButtonReleaseMask, release_button, data);
	mlx_hook(data->win, MotionNotify, PointerMotionMask, handle_mouse, data);
	mlx_loop_hook(data->mlx, check_keys, data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (printf("Error: You should enter \"./cub3D \
<maps_you_want.cub>\".\n"), 0);
	init_data(&data);
	check_input(av, &data);
	init_mlx(&data);
	create_imgs(&data, av);
	which_position(&data);
	if (strcmp(av[1], "maps/horde_zombie.cub") == 0 || \
		strcmp(av[1], "maps/mapgpt.cub") == 0 || \
		strcmp(av[1], "maps/giant_map.cub") == 0)
		data.pid_music = start_music();
	handle_events(&data);
	mlx_loop(data.mlx);
	return (0);
}
