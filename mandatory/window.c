/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:30:28 by hasserao          #+#    #+#             */
/*   Updated: 2022/12/28 17:39:06 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_images(t_game *game)
{
	game->screen_img = mlx_xpm_file_to_image(game->mlx, \
		"mandatory/img/screen.xpm", &game->img_width, &game->img_height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, \
		"mandatory/img/wall.xpm", &game->img_width, &game->img_height);
	game->player_img = mlx_xpm_file_to_image(game->mlx, \
		"mandatory/img/player1.xpm", &game->img_width, &game->img_height);
	game->collect_img = mlx_xpm_file_to_image(game->mlx, \
		"mandatory/img/collectible.xpm", &game->img_width, &game->img_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, \
		"mandatory/img/exit.xpm", &game->img_width, &game->img_height);
	if (!game->screen_img || !game->wall_img || !game->player_img
		|| !game->collect_img || !game->exit_img)
	{
		ft_printf("Invalid xpm image \n");
		exit (0);
	}
}

static void	set_player(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->player_img, y * 64, x * 64);
	game->x_player = x;
	game->y_player = y;
}

static void	set_collect(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->collect_img, y * 64, x * 64);
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
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->screen_img, j * 64, i * 64);
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->wall_img, j * 64, i * 64);
			if (game->map[i][j] == 'P')
				set_player(game, i, j);
			if (game->map[i][j] == 'C')
				set_collect(game, i, j);
			if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->exit_img, j * 64, i * 64);
		}
	}
}
