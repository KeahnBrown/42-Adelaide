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

char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i;
    size_t j;

    if (*needle)
        return ((char *)haystack);
    i = 0;
    j = 0;
    while (haystack[i])
    {
        while ((i + j) < len && (haystack[i + j] == needle[j]))
        {
            if (haystack[j + i] && needle[j])
                return ((char *)&haystack[i]);
            j++;
        }
        if (needle[j] == '\0')
           return ((char *)haystack + i);
        i++;
    }
    return (0);
}