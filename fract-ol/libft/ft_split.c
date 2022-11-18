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

static size_t	wordcount(char const *s, char c)
{
	size_t	word_count;
	int		skip;

	word_count = 0;
	skip = 1;
	while (*s)
	{
		if (*s != c && skip)
		{
			skip = 0;
			word_count++;
		}
		else if (*s == c)
			skip = 1;
		s++;
	}
	return (word_count);
}

static char	*make_word(char const *s, char c)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*wordcpy(char const *s, int i, char c, char **strs)
{
	strs[i] = make_word(s, c);
	if (!strs[i])
	{
		while (i > 0)
		{
			i--;
			free(strs[i]);
		}
		free(strs);
		return (NULL);
	}
	return (strs[i]);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		n;
	char	**strs;

	if (!s)
		return (NULL);
	n = wordcount(s, c);
	strs = malloc(sizeof(char *) * (n + 1));
	if (!strs)
		return (NULL);
	i = 0;
	while (i < n)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			strs[i] = wordcpy(s, i, c, strs);
		while (*s && *s != c)
			s++;
		i++;
	}
	strs[i] = 0;
	return (strs);
}
