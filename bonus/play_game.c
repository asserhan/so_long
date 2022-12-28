/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:34:54 by hasserao          #+#    #+#             */
/*   Updated: 2022/12/28 21:33:15 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_up(t_game *game, int keycode)
{
	int	c;

	update_player(game, keycode);
	if (game->x_player == 0 || game->map[game->x_player - 1] \
		[game->y_player] == '1')
		return (0);
	game->x_player--;
	c = ft_play(game);
	if (!c)
	{
		game->x_player++;
		return (0);
	}
	game->map[game->x_player + 1][game->y_player] = '0';
	ft_printf("The number of mouvement is %d \n", game->movement);
	return (1);
}

static int	move_down(t_game *game, int keycode)
{
	int	c;

	update_player(game, keycode);
	if (game->x_player + 1 >= game->height || game->map[game->x_player + 1] \
		[game->y_player] == '1')
		return (0);
	game->x_player++;
	c = ft_play(game);
	if (!c)
	{
		game->x_player--;
		return (0);
	}
	game->map[game->x_player - 1][game->y_player] = '0';
	ft_printf("The number of mouvement is %d \n", game->movement);
	return (1);
}

static int	move_left(t_game *game, int keycode)
{
	int	c;

	update_player(game, keycode);
	if (game->y_player == 0 || game->map[game->x_player] \
		[game->y_player - 1] == '1')
		return (0);
	game->y_player--;
	c = ft_play(game);
	if (!c)
	{
		game->y_player++;
		return (0);
	}
	game->map[game->x_player][game->y_player + 1] = '0';
	ft_printf("The number of mouvement is %d \n", game->movement);
	return (1);
}

static int	move_right(t_game *game, int keycode)
{
	int	c;

	update_player(game, keycode);
	if (game->y_player + 1 >= game->width || game->map[game->x_player] \
		[game->y_player + 1] == '1')
		return (0);
	game->y_player++;
	c = ft_play(game);
	if (!c)
	{
		game->y_player--;
		return (0);
	}
	game->map[game->x_player][game->y_player - 1] = '0';
	ft_printf("The number of mouvement is %d \n", game->movement);
	return (1);
}

int	key_hook(int keycode, t_game *game)
{
	int	c;

	if (keycode == K_ESC || keycode == K_Q)
		close_game(game);
	if (keycode == K_W)
		c = move_up(game, keycode);
	if (keycode == K_S)
		c = move_down(game, keycode);
	if (keycode == K_A)
		c = move_left(game, keycode);
	if (keycode == K_D)
		c = move_right(game, keycode);
	if (c)
	{
		mlx_clear_window(game->mlx, game->mlx_win);
		put_images(game);
	}
	return (1);
}
