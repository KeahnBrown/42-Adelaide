/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:56:07 by kbrown            #+#    #+#             */
/*   Updated: 2022/06/28 15:32:42 by kbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexp(void *p)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	i += ft_convert((unsigned long)p, 16, 1);
	return (i);
}
