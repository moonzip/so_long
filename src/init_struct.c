/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmart3 <lucmart3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:25:12 by lucmart3          #+#    #+#             */
/*   Updated: 2024/09/03 20:36:08 by lucmart3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_game *game)
{
	game->map = NULL;
	game->map_copy = NULL;
	game->i = 0;
	game->j = 0;
	game->x = 0;
	game->y = 0;
	game->z = -1;
	game->c_player = 0;
	game->c_exit = 0;
	game->c_exit_copy = 0;
	game->c_collect = 0;
	game->c_collect_copy = 0;
	game->moves = 0;
}
