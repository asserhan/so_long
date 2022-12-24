/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 01:53:11 by hasserao          #+#    #+#             */
/*   Updated: 2022/12/23 19:04:36 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void kill_player(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player_img);
	mlx_destroy_image(game->mlx,game->screen_img);
    mlx_destroy_image(game->mlx,game->exit_img);
    mlx_destroy_image(game->mlx,game->collect_img);
    mlx_destroy_image(game->mlx,game->wall_img);
    mlx_destroy_image(game->mlx,game->enemy_img);
	mlx_clear_window(game->mlx, game->mlx_win);
	game->img = mlx_xpm_file_to_image
		(game->mlx, "game_over.xpm", &game->img_width, &game->img_height);
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->img,0, 0);
    ft_printf("You lose!");
}