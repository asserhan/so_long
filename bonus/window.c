/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:30:28 by hasserao          #+#    #+#             */
/*   Updated: 2022/12/28 21:48:53 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_player(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->player_img, y * 64, x * 64);
	game->x_player = x;
	game->y_player = y;
}

static void	set_collect(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->collect_img, y * 64, x * 64);
}

static void	set_enemy(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->enemy_img, y * 64, x * 64);
}

static void	set_exit(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->exit_img, y * 64, x * 64);
}

void	put_images(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i] != NULL)
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
					game->screen_img, j * 64, i * 64);
			if (game->map[i][j] == '1')
				set_walls(game, i, j);
			if (game->map[i][j] == 'P')
				set_player(game, i, j);
			if (game->map[i][j] == 'C')
				set_collect(game, i, j);
			if (game->map[i][j] == 'E')
				set_exit(game, i, j);
			if (game->map[i][j] == 'X')
				set_enemy(game, i, j);
		}
		display_score(game);
	}
}
