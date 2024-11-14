/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:37:24 by matle-br          #+#    #+#             */
/*   Updated: 2024/06/07 11:40:16 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_format(char c)
{
	char	*str;

	str = "cspdiuxX%";
	while (*str)
	{
		if (*str == c)
			return (0);
		str++;
	}
	return (1);
}

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit((long)(va_arg(ap, int)), 10, 0);
	else if (specifier == 'x')
		count += print_digit((long)(va_arg(ap, unsigned int)), 16, 0);
	else if (specifier == 'X')
		count += print_digit((long)(va_arg(ap, unsigned int)), 16, 1);
	else if (specifier == 'p')
		count += print_address(va_arg(ap, void *));
	else if (specifier == 'u')
		count += print_digit((long)(va_arg(ap, unsigned int)), 10, 1);
	else if (specifier == '%')
		count += write (1, "%", 1);
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%' && (check_format(*(format + 1)) == 0))
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
