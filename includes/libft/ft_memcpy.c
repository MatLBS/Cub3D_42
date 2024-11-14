/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:42:56 by matle-br          #+#    #+#             */
/*   Updated: 2024/05/21 18:21:53 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*char_dest;
	const char	*char_src;
	size_t		i;

	if (dest == NULL && src == NULL)
		return (NULL);
	char_dest = (char *) dest;
	char_src = (char *) src;
	i = 0;
	while (i < n)
	{
		*char_dest++ = *char_src++;
		i++;
	}
	return (dest);
}
