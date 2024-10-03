/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmart3 <lucmart3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:33:02 by lucmart3          #+#    #+#             */
/*   Updated: 2024/04/30 12:41:55 by lucmart3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	wordlen(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static void	free_array(char **buffer, int is)
{
	while (is > 0)
	{
		is--;
		free(buffer[is]);
	}
	free (buffer);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	int		i;
	int		is;

	i = 0;
	is = -1;
	buffer = malloc(sizeof(char *) * (word(s, c) + 1));
	if (!buffer)
		return (NULL);
	while (++is < word(s, c))
	{
		while (s[i] == c)
			i++;
		buffer[is] = ft_substr(s, i, wordlen(s, c, i));
		if (!(buffer[is]))
		{
			free_array(buffer, is);
			return (0);
		}
		i += wordlen(s, c, i);
	}
	buffer[is] = NULL;
	return (buffer);
}
