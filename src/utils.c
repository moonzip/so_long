/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmart3 <lucmart3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:04:35 by lucmart3          #+#    #+#             */
/*   Updated: 2024/10/03 18:07:59 by lucmart3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_game *game)
{
	game->i = 0;
	if (game->map != NULL)
	{
		while (game->map[game->i] != NULL)
			free (game->map[game->i++]);
		free (game->map);
	}
	game->i = 0;
	if (game->map_copy != NULL)
	{
		while (game->map_copy[game->i] != NULL)
			free (game->map_copy[game->i++]);
		free (game->map_copy);
	}
	free (game);
}

void	flood_fill(t_game *game, t_position player, t_position size)
{
	if (player.x >= size.y || player.y >= size.x || player.x < 0
		|| player.y < 0 || game->map_copy[player.x][player.y] == '1'
		|| game->map_copy[player.x][player.y] == '@')
		return ;
	if (game->map_copy[player.x][player.y] == 'C')
		game->c_collect_copy++;
	if (game->map_copy[player.x][player.y] == 'E')
		game->c_exit_copy++;
	game->map_copy[player.x][player.y] = '@';
	flood_fill(game, (t_position){player.x + 1, player.y}, size);
	flood_fill(game, (t_position){player.x - 1, player.y}, size);
	flood_fill(game, (t_position){player.x, player.y + 1}, size);
	flood_fill(game, (t_position){player.x, player.y - 1}, size);
}

int	valid_way(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_copy[i])
		ft_printf ("%s\n", game->map_copy[i++]);
	flood_fill(game, game->player, (t_position){game->x, game->y});
	if (game->c_collect != game->c_collect_copy
		|| game->c_exit != game->c_exit_copy)
		return (ft_printf("Error\nInvalid path\n"), EXIT_FAILURE);
	game->c_collect = 0;
	return (EXIT_SUCCESS);
}

void	close_game(void *p)
{
	t_game	*close;

	close = p;
	mlx_close_window(close->mlx);
}
