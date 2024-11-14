/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:32:15 by matle-br          #+#    #+#             */
/*   Updated: 2024/11/07 13:46:20 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_space(t_data *data, char **tab, int i, int j)
{
	while (tab[i][++j])
	{
		if (tab[i][j] == ' ')
		{
			if (j > 0 && (tab[i][j + 1] != '\0') && (\
				(tab[i][j - 1] != '1' && tab[i][j - 1] != ' ') || \
				(tab[i][j + 1] != '1' && tab[i][j + 1] != ' ') || \
				(tab[i - 1][j] != '1' && tab[i - 1][j] != ' ') || \
				(tab[i + 1][j] != '1' && tab[i + 1][j] != ' ')))
			{
				printf("Error : Map not closed on line %d.\n", i);
				return (ft_free_data(data), exit(EXIT_FAILURE), 0);
			}
		}
		if (tab[i][j] == '0')
		{
			if (tab[i][j - 1] == '\0' || tab[i][j + 1] == '\0' || \
				tab[i - 1][j] == '\0' || tab[i + 1][j] == '\0')
			{
				printf("Error : Map not closed on line %d.\n", i);
				return (ft_free_data(data), exit(EXIT_FAILURE), 0);
			}
		}
	}
	return (1);
}

int	check_line(char *str, t_data *data, int y, int i)
{
	if (str[0] == '\0' || data->map->map[y + 1][0] == '\0')
	{
		printf("Error : Empty line in the map.\n");
		return (ft_free_data(data), exit(EXIT_FAILURE), 0);
	}
	while (str[++i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != ' ' && str[i] != 'N' \
		&& str[i] != 'S' && str[i] != 'E' && str[i] != 'W' \
			&& str[i] != 'D' && str[i] != 'Z')
		{
			printf("Error : Bad input in the map.\n");
			return (ft_free_data(data), exit(EXIT_FAILURE), 0);
		}
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
		{
			data->map->player += 1;
			data->player->posx = i + 0.5;
			data->player->posy = y + 0.5;
			data->map->pos_player = str[i];
		}
		if (str[i] == 'Z')
			handle_sprites(data, y, i);
	}
	return (1);
}

int	check_first_line(char **tab, t_data *data, int i, int j)
{
	if (data->map->map[i + 1] == NULL)
	{
		printf("Error : There is only one line.\n");
		return (ft_free_data(data), exit(EXIT_FAILURE), 0);
	}
	while (tab[i][++j])
	{
		if (tab[i][j] != '1' && tab[i][j] != ' ')
		{
			printf("Error : Bad input on first line.\n");
			return (ft_free_data(data), exit(EXIT_FAILURE), 0);
		}
		if (tab[i][j] == ' ')
		{
			if (j > 0 && (tab[i][j + 1] != '\0') && ((tab[i][j - 1] \
				!= '1' && tab[i][j - 1] != ' ') || \
				(tab[i][j + 1] != '1' && tab[i][j + 1] != ' ') || \
				(tab[i + 1][j] != '1' && tab[i + 1][j] != ' ')))
			{
				printf("Error : Map not closed on first line.\n");
				return (ft_free_data(data), exit(EXIT_FAILURE), 0);
			}
		}
	}
	return (1);
}

int	check_last_line(char **tab, t_data *data, int i)
{
	int	j;

	j = -1;
	while (tab[i][++j])
	{
		if (tab[i][j] != '1' && tab[i][j] != ' ')
		{
			printf("Error : Bad input on last line.\n");
			ft_free_data(data);
			return (exit(EXIT_FAILURE), 0);
		}
		if (tab[i][j] == ' ')
		{
			if (j > 0 && (tab[i][j + 1] != '\0') && \
				((tab[i][j - 1] != '1' && tab[i][j - 1] != ' ') || \
				(tab[i][j + 1] != '1' && tab[i][j + 1] != ' ') || \
				(tab[i - 1][j] != '1' && tab[i - 1][j] != ' ')))
			{
				printf("Error : Map not closed on last line.\n");
				ft_free_data(data);
				return (exit(EXIT_FAILURE), 0);
			}
		}
	}
	return (1);
}

int	check_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->map[i][0] == '\0')
		i++;
	check_first_line(data->map->map, data, i, -1);
	i++;
	while (data->map->map[i + 1])
	{
		check_line(data->map->map[i], data, i, -1);
		check_sides(data->map->map[i], data);
		check_space(data, data->map->map, i, -1);
		i++;
	}
	check_last_line(data->map->map, data, i);
	if (data->map->player > 1 || data->map->player == 0)
	{
		printf("Error : There is not the right numbers of player on the map.\n");
		ft_free_data(data);
		return (exit(EXIT_FAILURE), 0);
	}
	return (1);
}
