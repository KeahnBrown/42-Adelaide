/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:08:57 by kbrown            #+#    #+#             */
/*   Updated: 2022/06/28 15:29:08 by kbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_arguments(const char c, va_list *arg, int *i)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*arg, int)));
	else if ((c == 'd') || (c == 'i'))
		return (ft_putnbr(va_arg(*arg, int)));
	else if (c == 'u')
		return (ft_convert(va_arg(*arg, unsigned int), 10, 1));
	else if (c == 's')
		return (ft_putstr(va_arg(*arg, char *)));
	else if (c == 'x')
		return (ft_convert(va_arg(*arg, unsigned int), 16, 1));
	else if (c == 'X')
		return (ft_convert(va_arg(*arg, unsigned int), 16, 0));
	else if (c == 'p')
		return (ft_puthexp(va_arg(*arg, void *)));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		(*i)--;
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		length;

	va_start(arg, format);
	i = 0;
	length = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			length += ft_arguments(format[i], &arg, &i);
		}
		else
			length += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (length);
}
