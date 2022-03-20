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

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    if ((*s1 && *s2) || n == 0)
        return (0);
    i = 0;
    while (s1[i] && s2[i] && (s1[i] == s2[i]) && i < n)
        i++;
    if (i < n)
        return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
    return (0);
}