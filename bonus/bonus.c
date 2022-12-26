/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 01:53:11 by hasserao          #+#    #+#             */
/*   Updated: 2022/12/25 01:06:14 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void display_score(t_game *game)
{
    char *move;
    move = ft_itoa(game->movement);
    mlx_string_put(game->mlx,game->mlx_win,50,20,0x00FF0000,"Number of mouvement : ");
    mlx_string_put(game->mlx,game->mlx_win,150,40,0x00FF0000,move);
    free (move);
}

int loop_hook(t_game *game)
{
    if (game->rate < 1000)
    {
        game->rate++;
        return (0);
    }
    game->rate = 0;
    mlx_destroy_image(game->mlx,game->enemy_img);
    if (game->sprite == 1)
        game->enemy_img = mlx_xpm_file_to_image(game->mlx,"enemy1.xpm",&game->img_width,&game->img_height);
    if(game->sprite == 2)
    {
         game->enemy_img = mlx_xpm_file_to_image(game->mlx,"enemy2.xpm",&game->img_width,&game->img_height);
         game->sprite = 1;
    }
    mlx_clear_window(game->mlx,game->mlx_win);
    put_images(game);
    game->sprite++;
    return (0);
}