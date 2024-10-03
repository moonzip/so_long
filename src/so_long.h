/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmart3 <lucmart3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:10:11 by lucmart3          #+#    #+#             */
/*   Updated: 2024/10/03 17:54:59 by lucmart3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_game
{
	char			**map;
	int				y;
	int				x;
	int				i;
	int				j;
	int				z;
	int				moves;
	t_position		player;
	t_position		exit;
	int				c_player;
	int				c_exit;
	int				c_collect;
	int				c_collect_copy;
	int				c_exit_copy;
	char			**map_copy;
	mlx_texture_t	*t_f;
	mlx_image_t		*i_f;
	mlx_texture_t	*t_w;
	mlx_image_t		*i_w;
	mlx_texture_t	*t_oe;
	mlx_image_t		*i_oe;
	mlx_texture_t	*t_ce;
	mlx_image_t		*i_ce;
	mlx_texture_t	*t_g;
	mlx_image_t		*i_g;
	mlx_texture_t	*t_d_pc;
	mlx_image_t		*i_d_pc;
	mlx_texture_t	*t_up_pc;
	mlx_image_t		*i_up_pc;
	mlx_texture_t	*t_l_pc;
	mlx_image_t		*i_l_pc;
	mlx_texture_t	*t_r_pc;
	mlx_image_t		*i_r_pc;
	mlx_t			*mlx;
}	t_game;

void	init_struct(t_game *game);
int		check_extension(char *ber);
int		line_walls(t_game *game);
int		other_walls(t_game *game);
int		elements(t_game *game);
int		read_map(char **argv, t_game *game);
int		create_image(t_game *g);
void	init_game(t_game *g);
void	free_all(t_game *game);
void	flood_fill(t_game *game, t_position player, t_position size);
int		valid_way(t_game *game);
void	close_game(void *p);
void	keyhook(mlx_key_data_t keydata, void *p);

#endif