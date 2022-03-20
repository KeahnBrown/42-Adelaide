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

size_t  ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
{
    size_t  i;

    if (!dst || !src || dstsize < 0)
        return (0);
    i = 0;
    while (*src++ || dstsize--)
    {
        ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
        i++;
    }
    ((unsigned char *)dst)[i] = '\0';
    return (ft_strlen(src));
}

