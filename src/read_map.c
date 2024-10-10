/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmart3 <lucmart3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:54:35 by lucmart3          #+#    #+#             */
/*   Updated: 2024/10/08 11:50:57 by lucmart3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	read_lines(t_game *game, int fd, char *line)
{
	while (line != NULL)
	{
		game->y++;
		free(line);
		line = get_next_line(fd);
	}
}

int	read_map2(int fd, t_game *game, char *line)
{
	while (game->i < game->y)
	{
		game->x = ft_strlen(line);
		game->map[game->i] = malloc(sizeof(char) * game->x + 1);
		game->map_copy[game->i] = malloc(sizeof(char *) * game->x + 1);
		if (!game->map[game->i] || !game->map_copy[game->i])
			return (EXIT_FAILURE);
		if (game->i == game->y - 1)
		{
			ft_strlcpy(game->map[game->i], line, game->x + 1);
			ft_strlcpy(game->map_copy[game->i], line, game->x + 1);
		}
		else
		{
			ft_strlcpy(game->map[game->i], line, game->x);
			ft_strlcpy(game->map_copy[game->i], line, game->x);
		}
		game->i++;
		free(line);
		line = get_next_line(fd);
	}
	game->map[game->i] = NULL;
	game->map_copy[game->i] = NULL;
	return (EXIT_SUCCESS);
}

int	read_map(char **argv, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nMap not found\n"), EXIT_FAILURE);
	line = get_next_line(fd);
	if (!line)
		return (EXIT_FAILURE);
	read_lines(game, fd, line);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	game->map = malloc(sizeof(char *) * game->y + 1);
	game->map_copy = malloc(sizeof(char *) * game->y + 1);
	if (!game->map || !game->map_copy)
		return (EXIT_FAILURE);
	line = get_next_line(fd);
	if (!line)
		return (EXIT_FAILURE);
	if (read_map2(fd, game, line) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	close (fd);
	return (EXIT_SUCCESS);
}
