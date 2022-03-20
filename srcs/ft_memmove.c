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

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    size_t  i;

    i = 0;
    if (!dst && !src)
        return (0);
    if (((size_t)src < (size_t)dst) && ((size_t)dst < (size_t)src + len))
    {
        i = len - 1;
        while (i)
        {
            ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
            i--;
        }
    }
    else
    {
        while (len--)
        {
            ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
            i++;
        }
    }
    return (dst);
}