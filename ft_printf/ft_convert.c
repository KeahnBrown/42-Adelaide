/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:00:41 by kbrown            #+#    #+#             */
/*   Updated: 2022/06/28 15:27:23 by kbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(unsigned long num, int base, int uporlow)
{
	char		*representation;
	static char	buffer[50];
	char		*ptr;

	if (num == 0)
		return (ft_putchar('0'));
	if (uporlow == 0)
		representation = "0123456789ABCDEF";
	else
		representation = "0123456789abcdef";
	ptr = &buffer[49];
	*ptr = '\0';
	while (num)
	{
		*--ptr = representation[num % base];
		num = num / base;
	}
	return (ft_putstr(ptr));
}
