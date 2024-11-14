/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:59:36 by matle-br          #+#    #+#             */
/*   Updated: 2024/11/07 14:06:08 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_sides(char *str, t_data *data)
{
	int	i;

	i = ft_isspace(str);
	if (str[i] != '1')
	{
		printf("Error : Map not closed on left side.\n");
		ft_free_data(data);
		return (exit(EXIT_FAILURE), 0);
	}
	while (str[i + 1] != '\0')
		i++;
	while (str[i] == ' ')
		i--;
	if (str[i] != '1')
	{
		printf("Error : Map not closed on right side.\n");
		ft_free_data(data);
		return (exit(EXIT_FAILURE), 0);
	}
	return (1);
}

int	check_number(char *str)
{
	int	i;
	int	nb_comma;

	i = 0;
	nb_comma = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && (str[i] == ',' && !ft_isdigit(str[i + 1])))
			return (0);
		if (str[i] == ',')
			nb_comma++;
		i++;
	}
	if (nb_comma != 2)
		return (0);
	return (1);
}

void	ft_strcpy_cub(char *dest, char *src, int size, int j)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*temp;
	size_t	copy_size;

	temp = malloc(new_size);
	if (!temp)
		return (NULL);
	if (ptr)
	{
		if (old_size < new_size)
			copy_size = old_size;
		else
			copy_size = new_size;
		ft_memcpy(temp, ptr, copy_size);
		free(ptr);
	}
	return (temp);
}

void	handle_sprites(t_data *data, int y, int i)
{
	static int	nb;

	data->num_sprites++;
	data->sprites = ft_realloc(data->sprites, sizeof(t_sprites) * \
		nb, sizeof(t_sprites) * (nb + 2));
	data->sprites[nb].posx = i + 0.5;
	data->sprites[nb].posy = y + 0.5;
	data->sprites[nb].spritescreenx = 0;
	data->sprites[nb].spriteheight = 0;
	data->sprites[nb].drawstarty = 0;
	data->sprites[nb].drawendy = 0;
	data->sprites[nb].spritewidth = 0;
	data->sprites[nb].drawendx = 0;
	data->sprites[nb].drawstartx = 0;
	data->sprites[nb].texx = 0;
	data->sprites[nb].texy = 0;
	data->sprites[nb].stripe = 0;
	data->sprites[nb].spriteorder = -1;
	data->sprites[nb].spritex = 0.0;
	data->sprites[nb].spritey = 0.0;
	data->sprites[nb].invdet = 0.0;
	data->sprites[nb].transformx = 0.0;
	data->sprites[nb].transformy = 0.0;
	data->sprites[nb].spritedistance = -1;
	nb++;
}
