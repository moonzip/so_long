/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmart3 <lucmart3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:38:08 by lucmart3          #+#    #+#             */
/*   Updated: 2024/10/08 16:45:33 by lucmart3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *ber)
{
	int	i;

	i = ft_strlen(ber);
	if (ber[i - 1] == 'r' && ber[i - 2] == 'e'
		&& ber[i - 3] == 'b' && ber[i - 4] == '.')
		return (EXIT_SUCCESS);
	else
		return (ft_printf("Error\nInvalid extension\n"), EXIT_FAILURE);
}

int	line_walls(t_game *game)
{
	game->i = 0;
	game->j = ft_strlen(game->map[game->i]);
	while (game->map[game->i])
	{
		if (ft_strlen(game->map[game->i]) != (size_t)game->j)
			return (ft_printf("Error\nDifferent size\n"), EXIT_FAILURE);
		game->i++;
	}
	game->j = 0;
	while (game->map[game->j] != NULL)
	{
		game->i = 0;
		while (game->map[game->j][game->i] != '\0')
		{
			if (game->map[0][game->i] != '1'
				|| game->map[game->y - 1][game->i] != '1')
				return (ft_printf("Error\nFail with walls\n"), EXIT_FAILURE);
			game->i++;
		}
		game->j++;
	}
	return (EXIT_SUCCESS);
}

int	other_walls(t_game *game)
{
	game->i = 1;
	while (game->map[game->i] && game->i < game->y - 1)
	{
		if (game->map[game->i][0] != '1'
		|| game->map[game->i][game->x - 1] != '1')
			return (ft_printf("Error\nFail with walls\n"), EXIT_FAILURE);
		game->i++;
	}
	return (EXIT_SUCCESS);
}

int	elements(t_game *game)
{
	game->i = -1;
	while (game->map[++game->i])
	{
		game->j = -1;
		while (game->map[game->i][++game->j] != '\0')
		{
			if (game->map[game->i][game->j] == 'P')
			{
				game->player.y = game->j;
				game->player.x = game->i;
				game->c_player++;
			}
			if (game->map[game->i][game->j] == 'E')
			{
				game->exit.y = game->i;
				game->exit.x = game->j;
				game->c_exit++;
			}
			if (game->map[game->i][game->j] == 'C')
				game->c_collect++;
		}
	}
	if (game->c_player != 1 || game->c_exit != 1 || game->c_collect < 1)
		return (ft_printf("Error\nInvalid elements\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
