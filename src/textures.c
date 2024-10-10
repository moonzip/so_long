/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmart3 <lucmart3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:33:23 by lucmart3          #+#    #+#             */
/*   Updated: 2024/10/01 16:53:54 by lucmart3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_clean_textures(t_game *g)
{
	mlx_delete_texture(g->t_f);
	mlx_delete_texture(g->t_w);
	mlx_delete_texture(g->t_oe);
	mlx_delete_texture(g->t_ce);
	mlx_delete_texture(g->t_g);
	mlx_delete_texture(g->t_d_pc);
	mlx_delete_texture(g->t_up_pc);
	mlx_delete_texture(g->t_l_pc);
	mlx_delete_texture(g->t_r_pc);
}

int	create_image(t_game *g)
{
	g->t_f = mlx_load_png("/home/lucmart3/Desktop/so_long/sprites/floor.png");
	g->t_w = mlx_load_png("/home/lucmart3/Desktop/so_long/sprites/wall.png");
	g->t_oe = mlx_load_png("/home/lucmart3/Desktop/so_long/sprites/o_exit.png");
	g->t_ce = mlx_load_png("/home/lucmart3/Desktop/so_long/sprites/c_exit.png");
	g->t_g = mlx_load_png("/home/lucmart3/Desktop/so_long/sprites/gomu.png");
	g->t_d_pc = mlx_load_png("/home/lucmart3/Desktop/so_long/sprites/d_pc.png");
	g->t_up_pc = mlx_load_png("/home/lucmart3/Desktop/so_long/sprites/u_p.png");
	g->t_l_pc = mlx_load_png("/home/lucmart3/Desktop/so_long/sprites/l_pc.png");
	g->t_r_pc = mlx_load_png("/home/lucmart3/Desktop/so_long/sprites/r_pc.png");
	g->i_f = mlx_texture_to_image(g->mlx, g->t_f);
	g->i_w = mlx_texture_to_image(g->mlx, g->t_w);
	g->i_oe = mlx_texture_to_image(g->mlx, g->t_oe);
	g->i_ce = mlx_texture_to_image(g->mlx, g->t_ce);
	g->i_g = mlx_texture_to_image(g->mlx, g->t_g);
	g->i_d_pc = mlx_texture_to_image(g->mlx, g->t_d_pc);
	g->i_up_pc = mlx_texture_to_image(g->mlx, g->t_up_pc);
	g->i_l_pc = mlx_texture_to_image(g->mlx, g->t_l_pc);
	g->i_r_pc = mlx_texture_to_image(g->mlx, g->t_r_pc);
	if (!g->t_f || !g->t_w || !g->t_oe || !g->t_ce || !g->t_g
		|| !g->t_d_pc || !g->t_up_pc || !g->t_l_pc || !g->t_r_pc || !g->i_f
		|| !g->i_w || !g->i_oe || !g->i_ce || !g->i_g || !g->i_d_pc
		|| !g->i_up_pc || !g->i_l_pc || !g->i_r_pc)
		return (EXIT_FAILURE);
	ft_clean_textures(g);
	return (EXIT_SUCCESS);
}

void	init_game(t_game *g)
{
	while (g->map[++g->z])
	{
		g->i = -1;
		while (g->map[g->z][++g->i])
		{
			if (g->map[g->z][g->i] == 'P' || g->map[g->z][g->i] == 'C'
				|| g->map[g->z][g->i] == 'E')
				mlx_image_to_window(g->mlx, g->i_f, g->i * 60, g->z * 60);
			if (g->map[g->z][g->i] == '1')
				mlx_image_to_window(g->mlx, g->i_w, g->i * 60, g->z * 60);
			if (g->map[g->z][g->i] == '0')
				mlx_image_to_window(g->mlx, g->i_f, g->i * 60, g->z * 60);
			if (g->map[g->z][g->i] == 'P')
				mlx_image_to_window(g->mlx, g->i_r_pc, g->i * 60, g->z * 60);
			if (g->map[g->z][g->i] == 'C')
				mlx_image_to_window(g->mlx, g->i_g, g->i * 60, g->z * 60);
			if (g->map[g->z][g->i] == 'E')
				mlx_image_to_window(g->mlx, g->i_ce, g->i * 60, g->z * 60);
		}
	}
}
