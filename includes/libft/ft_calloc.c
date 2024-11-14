/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:08:59 by matle-br          #+#    #+#             */
/*   Updated: 2024/05/21 13:30:09 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;
	size_t	total_size;

	total_size = (nmemb * size);
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	str = malloc(total_size);
	if (str == NULL)
		return (0);
	ft_memset(str, 0, total_size);
	return (str);
}
