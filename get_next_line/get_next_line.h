/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:30:59 by kbrown            #+#    #+#             */
/*   Updated: 2022/07/01 12:31:01 by kbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strdup(void);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(const char *str, unsigned int start, size_t len);
char	*ft_strchr(const char *str, int c);
int		ft_strlen(const char *str);

#endif
