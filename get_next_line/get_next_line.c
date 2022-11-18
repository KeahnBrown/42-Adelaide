/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:46:23 by kbrown            #+#    #+#             */
/*   Updated: 2022/06/30 13:47:12 by kbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*obtain_line(int fd, char *buffer, char *bufline)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!bufline)
			bufline = ft_strdup();
		temp = bufline;
		bufline = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (bufline);
}

static char	*return_line(char *line)
{
	size_t	len;
	char	*bufline;

	len = 0;
	while (line[len] != '\n' && line[len] != '\0')
		len++;
	if (line[len] == '\0')
		return (0);
	bufline = ft_substr(line, len + 1, ft_strlen(line) - len);
	if (*bufline == '\0')
	{
		free(bufline);
		bufline = 0;
	}
	line[len + 1] = '\0';
	return (bufline);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*bufline;

	if ((fd < 0) || (BUFFER_SIZE) <= 0)
		return (0);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	line = obtain_line(fd, buffer, bufline);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	bufline = return_line(line);
	return (line);
}
