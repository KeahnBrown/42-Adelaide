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

size_t  strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
    int dst_len;
    int src_len;
    int offset;
    size_t  i;

    dst_len = ft_strlen(dst);
    src_len = ft_strlen(src);
    offset = dst_len;

    i = 0;
    while (*src++ || --dstsize)
    {
        dst[offset] = src[i];
        i++;
        offset++;
    }
    dst[offset] = '\0';
    return (dst_len + src_len);
}