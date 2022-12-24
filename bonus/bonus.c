/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 01:53:11 by hasserao          #+#    #+#             */
/*   Updated: 2022/12/24 17:14:53 by hasserao         ###   ########.fr       */
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
void display_score(t_game *game)
{
    char *move;
    //char *data;
    move = ft_itoa(game->movement);
    mlx_string_put(game->mlx,game->mlx_win,50,20,0x00FF0000,"Number of mouvement : ")
    mlx_string_put(game->mlx,game->mlx_win,70,20,0x00FF0000,move);
    free (move;)
}
int loop_hook(t_game *game)
{
    static int k;
    k = 1 
    if (gamne->rate < 5000)
    {
        game->rate++;
        return (0);
    }
    game->rate = 0
    mlx_destroy_image(game->mlx;game->enemy_img);
    if (k == 1)
        game->enemy_img = mlx_xpm_file_to_image(game->mlx,".xpm",&game->img_width,&gane->img_height);
    if(k == 2)
    {
         game->enemy_img = mlx_xpm_file_to_image(game->mlx,".xpm",&game->img_width,&gane->img_height);
         k = 0;
    }
    put_images(game);
    k++;
    return (0);
}