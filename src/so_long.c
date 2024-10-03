/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmart3 <lucmart3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:27:06 by lucmart3          #+#    #+#             */
/*   Updated: 2024/10/03 17:54:56 by lucmart3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_map(t_game *game, char **argv)
{
	if (check_extension(argv[1]) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	if (read_map(argv, game) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	if (line_walls(game) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	if (other_walls(game) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	if (elements(game) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	if (valid_way(game) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (EXIT_FAILURE);
	if (argc != 2)
		return (ft_printf("Error\n"), EXIT_FAILURE);
	init_struct(game);
	if (check_map(game, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	game->mlx = mlx_init(game->x * 60, game->y * 60, "PACMAN", false);
	if (create_image(game) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	init_game(game);
	mlx_key_hook(game->mlx, &keyhook, game);
	mlx_close_hook(game->mlx, &close_game, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (free_all(game), EXIT_SUCCESS);
}
