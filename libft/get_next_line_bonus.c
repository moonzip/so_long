/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmart3 <lucmart3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:29:03 by lucmart3          #+#    #+#             */
/*   Updated: 2024/07/17 16:16:25 by lucmart3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_joined(char *buffer, char *res)
{
	char	*i;

	i = ft_strjoin_gnl(buffer, res);
	free (buffer);
	return (i);
}

static char	*read_file(int fd, char *text)
{
	int		to_read;
	char	*buffer;

	if (!text)
		text = ft_calloc_gnl(1, 1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	to_read = 1;
	while (to_read > 0)
	{
		to_read = read(fd, buffer, BUFFER_SIZE);
		if (to_read == -1)
		{
			free (text);
			free(buffer);
			return (NULL);
		}
		buffer[to_read] = '\0';
		text = ft_joined(text, buffer);
		if (ft_strchr_gnl(text, '\n'))
			break ;
	}
	free (buffer);
	return (text);
}

static char	*give_line(char *buffer)
{
	int		i;
	char	*newline;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	newline = ft_calloc_gnl(i + 2, sizeof(char));
	newline = ft_strncpy_gnl(newline, buffer, i + 1);
	if (buffer[i] == '\n')
		newline[i] = '\n';
	newline[i + 1] = '\0';
	return (newline);
}

static char	*cleantext(char *buffer)
{
	int		i;
	int		j;
	char	*newline;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	while (buffer[j] != '\0')
		j++;
	newline = ft_calloc_gnl((j - i + 1), sizeof(*buffer));
	if (!newline)
		return (NULL);
	j = 0;
	while (buffer[++i])
		newline[j++] = buffer[i];
	newline[j] = '\0';
	free (buffer);
	return (newline);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	newline = give_line(buffer[fd]);
	buffer[fd] = cleantext(buffer[fd]);
	return (newline);
}
