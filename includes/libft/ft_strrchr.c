/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:13:29 by matle-br          #+#    #+#             */
/*   Updated: 2024/05/21 19:58:15 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*last_occurr;

	c = ((unsigned char)(c % 256));
	i = 0;
	last_occurr = 0;
	if (c == 0)
		return ((char *) s + ft_strlen((char *)(s)));
	while (s[i] != '\0')
	{
		if (s[i] == (const char)c)
			last_occurr = (char *)&s[i];
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return ((char *)last_occurr);
}
