/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:32:11 by matle-br          #+#    #+#             */
/*   Updated: 2024/05/21 19:56:33 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nblen(int size)
{
	int	i;

	i = 0;
	if (size < 1)
		return (1);
	while (size > 0)
	{
		size /= 10;
		i++;
	}
	return (i);
}

char	*calcul(int len, int len1, int n, char *tab)
{
	tab[len] = '\0';
	while ((len - len1) > 0)
	{
		tab[len - 1] = n % 10 + '0';
		len--;
		n /= 10;
	}
	return (tab);
}

char	*check_min(void)
{
	char	*tab;
	char	*str;
	int		i;

	i = 0;
	str = "-2147483648";
	tab = malloc(sizeof(char) * 12);
	if (tab == NULL)
		return (NULL);
	while (str[i])
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*fill_in1(int flag, int len1, int n)
{
	char	*tab;
	int		len;

	len = ft_nblen(n) + len1;
	tab = malloc(sizeof(char) * (len + 1));
	if (tab == NULL)
		return (NULL);
	if (flag == 1)
		tab[0] = '-';
	calcul(len, len1, n, tab);
	return (tab);
}

char	*ft_itoa(int n)
{
	int		flag;
	char	*tab;
	int		len1;

	flag = 0;
	len1 = 0;
	if (n == -2147483648)
		return (check_min());
	else if (n < 0)
	{
		len1 = 1;
		n = -n;
		flag = 1;
	}
	tab = fill_in1(flag, len1, n);
	return (tab);
}
/*
int	main(void)
{
	printf("%s\n", ft_itoa(-55));
	return(0);
}*/
