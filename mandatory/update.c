/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:52:18 by hasserao          #+#    #+#             */
/*   Updated: 2022/12/28 17:39:01 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player(t_game *game, int keycode)
{
	mlx_destroy_image(game->mlx, game->player_img);
	if (keycode == K_W)
		game->player_img = mlx_xpm_file_to_image(game->mlx, \
			"mandatory/img/player1.xpm", &game->img_width, &game->img_height);
	if (keycode == K_S)
		game->player_img = mlx_xpm_file_to_image(game->mlx, \
			"mandatory/img/player1.xpm", &game->img_width, &game->img_height);
	if (keycode == K_A)
		game->player_img = mlx_xpm_file_to_image(game->mlx, \
			"mandatory/img/player1.xpm", &game->img_width, &game->img_height);
	if (keycode == K_D)
		game->player_img = mlx_xpm_file_to_image(game->mlx, \
			"mandatory/img/player2.xpm", &game->img_width, &game->img_height);
}

int	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->screen_img);
	mlx_destroy_image(game->mlx, game->exit_img);
	mlx_destroy_image(game->mlx, game->player_img);
	mlx_destroy_image(game->mlx, game->collect_img);
	mlx_destroy_image(game->mlx, game->wall_img);
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_destroy_window(game->mlx, game->mlx_win);
	free_map(game);
	exit(0);
	return (0);
}

int	ft_play(t_game *game)
{
	if (game->map[game->x_player][game->y_player] == 'E')
	{
		if (game->n_collect != 0)
			return (0);
		ft_printf("You win!\n");
		close_game(game);
	}
	if (game->map[game->x_player][game->y_player] == 'C')
	{
		game->map[game->x_player][game->y_player] = 'P';
		game->n_collect--;
		game->movement++;
	}
	if (game->map[game->x_player][game->y_player] == '0')
	{
		game->map[game->x_player][game->y_player] = 'P';
		game->movement++;
	}
	return (1);
}
