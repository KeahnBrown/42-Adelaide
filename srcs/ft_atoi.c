/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:46:47 by kbrown            #+#    #+#             */
/*   Updated: 2022/02/02 14:27:57 by kbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_atoi(const char *str)
{
    int sign;
    int i;
    int number;
    
    i = 0;
    sign = 1;
    while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
            str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
        i++;
    if (str[i] == '-')
        {sign = -1; i++;}
    else if (str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        number = (number * 10) + (str[i] - '0');
        i++;
    }
    return (number * sign);    
}