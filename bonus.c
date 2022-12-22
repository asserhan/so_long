/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 01:53:11 by hasserao          #+#    #+#             */
/*   Updated: 2022/12/22 02:22:50 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void kill_player(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player_img);
	mlx_clear_window(game->mlx, game->mlx_win);
	game->player_img = mlx_xpm_file_to_image
		(game->mlx, ".xpm", &game->img_width, &game->img_height);
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->player_img, game->x_player * 64, game->y_player * 64);
    ft_printf("You died!");
}