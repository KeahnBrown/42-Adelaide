/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:08:41 by kbrown            #+#    #+#             */
/*   Updated: 2022/09/23 13:08:45 by kbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		strequl(char *str1, char *str2)
{
	while (*str1 && *str2)
		if (!(*str1++ == *str2++)) {return (0);}
	if (*str1 == '\0' && *str2 == '\0')
		return (1);
	return (0);
}