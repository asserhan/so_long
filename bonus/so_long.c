/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:43:06 by hasserao          #+#    #+#             */
/*   Updated: 2022/12/26 18:29:37 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc,char	**argv)
{
	t_game game;
	int i;
	
	i = 0;
	if (argc == 2)
	{
		(void)argv;
		game.map = get_map("../map_files/map1.ber",&game);
		if (!game.map)
		{
			game.mlx = mlx_init();
			game.mlx_win = mlx_new_window(game.mlx,(game.width * 64),(game.height *64),"so_long");
			set_images(&game);
			put_images(&game);
			mlx_hook(game.mlx_win,2,0, key_hook,&game);
			mlx_hook(game.mlx_win,17,0,close_game,&game);
			//mlx_loop_hook(game.mlx,loop_hook ,&game);
			mlx_loop(game.mlx);
			
		}
		//∏system("leaks so_long");
	}
	return (0);	
}