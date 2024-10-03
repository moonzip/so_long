/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmart3 <lucmart3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:32:13 by lucmart3          #+#    #+#             */
/*   Updated: 2024/10/03 18:02:26 by lucmart3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_to_collect(t_game *g, int x, int y, mlx_image_t *r_pc)
{
	mlx_image_to_window(g->mlx, g->i_f, g->player.y * 60, g->player.x * 60);
	if (g->map[g->player.x][g->player.y] == 'E')
		mlx_image_to_window(g->mlx, g->i_ce, \
			g->player.y * 60, g->player.x * 60);
	g->player.x = x;
	g->player.y = y;
	g->map[g->player.x][g->player.y] = '0';
	mlx_image_to_window (g->mlx, g->i_f, g->player.y * 60, g->player.x * 60);
	mlx_image_to_window (g->mlx, r_pc, g->player.y * 60, g->player.x * 60);
	g->c_collect++;
	g->moves++;
	if (g->c_collect == g->c_collect_copy)
		mlx_image_to_window(g->mlx, g->i_oe, g->exit.x * 60, g->exit.y * 60);
	ft_printf ("Moves: %d\n", g->moves);
}

static void	move_to_exit(t_game *g, int x, int y, mlx_image_t *r_pc)
{
	mlx_image_to_window (g->mlx, g->i_f, g->player.y * 60, g->player.x * 60);
	g->player.x = x;
	g->player.y = y;
	mlx_image_to_window (g->mlx, g->i_f, g->player.y * 60, g->player.x * 60);
	mlx_image_to_window (g->mlx, g->i_ce, g->player.y * 60, g->player.x * 60);
	mlx_image_to_window (g->mlx, r_pc, g->player.y * 60, g->player.x * 60);
	g->moves++;
	ft_printf ("Moves: %d\n", g->moves);
}

static void	move_other(t_game *g, int x, int y, mlx_image_t *r_pc)
{
	mlx_image_to_window(g->mlx, g->i_f, g->player.y * 60, g->player.x * 60);
	if (g->map[g->player.x][g->player.y] == 'E')
		mlx_image_to_window(g->mlx, g->i_ce, \
			g->player.y * 60, g->player.x * 60);
	g->player.x = x;
	g->player.y = y;
	mlx_image_to_window(g->mlx, r_pc, g->player.y * 60, g->player.x * 60);
	g->moves++;
	ft_printf("Moves : %d\n", g->moves);
}

void	moves(t_game *g, int x, int y, mlx_image_t *r_pc)
{
	if (g->map[x][y] == 'C')
		move_to_collect(g, x, y, r_pc);
	else if (g->map[x][y] == 'E' && g->c_collect == g->c_collect_copy)
		close_game (g);
	else if (g->map[x][y] == 'E')
		move_to_exit(g, x, y, r_pc);
	else if (g->map[x][y] != '1')
		move_other(g, x, y, r_pc);
}

void	keyhook(mlx_key_data_t keydata, void *p)
{
	t_game	*g;

	g = (t_game *)p;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		moves(g, g->player.x - 1, g->player.y, g->i_up_pc);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		moves(g, g->player.x, g->player.y - 1, g->i_l_pc);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		moves(g, g->player.x + 1, g->player.y, g->i_d_pc);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		moves(g, g->player.x, g->player.y + 1, g->i_r_pc);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_game(g);
}
