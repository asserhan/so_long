/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:34:54 by hasserao          #+#    #+#             */
/*   Updated: 2022/12/22 20:17:51 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_game(t_game *game)
{
    mlx_destroy_image(game->mlx,game->screen_img);
    mlx_destroy_image(game->mlx,game->exit_img);
    mlx_destroy_image(game->mlx,game->player_img);
    mlx_destroy_image(game->mlx,game->collect_img);
    mlx_destroy_image(game->mlx,game->wall_img);
    mlx_destroy_image(game->mlx,game->enemy_img);
	mlx_clear_window(game->mlx,game->mlx_win);
	mlx_destroy_window(game->mlx,game->mlx_win);
	free_map(game);
	exit(0);
	return(0);
}
static int ft_play(t_game *game)
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
	// if (game->map[game->x_player][game->y_player] == 'X')
	// 	return (kill_player(game),0);
	return (1);
}
static int move_up_down(t_game *game,int keycode)
{
	int c;

	c = 0;
	if(keycode == K_W)
	{
		if (game->x_player == 0 || game->map[game->x_player - 1][game->y_player] == '1')
			return (0);
		game->x_player--;
		c = ft_play(game);
		if (!c)
		{
			game->x_player++;
			return (0);
		}
		game->map[game->x_player + 1][game->y_player] = '0';
	}
	if(keycode == K_S)
	{
		if (game->x_player + 1 >= game->height || game->map[game->x_player + 1][game->y_player] == '1')
			return (0);
		game->x_player++;
		c = ft_play(game);
		if (!c)
		{
			game->x_player--;
			return (0);
		}
		game->map[game->x_player - 1][game->y_player] = '0';
	}
	return (1);
}

static int move_left_right(t_game *game,int keycode)
{
	int c;
	if(keycode == K_A)
	{
		if (game->y_player == 0 || game->map[game->x_player][game->y_player - 1] == '1')
			return (0);
		game->y_player--;
		c = ft_play(game);
		if (!c)
		{
			game->y_player++;
			return (0);
		}
		game->map[game->x_player][game->y_player + 1] = '0';
	}
	if(keycode == K_D)
	{
		if (game->y_player + 1 >= game->width || game->map[game->x_player][game->y_player + 1] == '1')
			return (0);
		game->y_player++;
		c = ft_play(game);
		if (!c)
		{
			game->y_player--;
			return (0);
		}
		game->map[game->x_player][game->y_player - 1] = '0';
	}
	return (1);
}
int key_hook(int keycode, t_game *game)
{
	int c;
	int i = 0;
	while(i < game->height && game->map != NULL)
		{
			ft_printf("%s\n",game->map[i]);
			i++;
		}
		ft_printf("====================================\n");
	if (keycode == K_esc || keycode == K_Q)
		close_game(game);
	if (keycode == K_W)
		c = move_up_down(game,keycode);
	if (keycode == K_S)
		c = move_up_down(game,keycode);
	if (keycode == K_A)
		c = move_left_right(game,keycode);
	if (keycode == K_D)
		c = move_left_right(game,keycode);
	if (c)
	{
		mlx_clear_window(game->mlx,game->mlx_win);
		put_images(game);
	}
	return (1);
	
}