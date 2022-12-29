/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:43:06 by hasserao          #+#    #+#             */
/*   Updated: 2022/12/29 15:10:00 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_collect(t_game *map, char *file)
{
	int	i;
	int	j;

	map->n_collect = 0;
	i = -1;
	while (map->map[++i] != NULL)
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'C')
			{
				if (!valid_path(map, file, i, j))
					return (0);
				map->n_collect++;
			}
		}
	}
	if (!(map->n_collect >= 1))
		return (0);
	return (1);
}

void	set_images(t_game *game)
{
	game->rate = 0;
	game->sprite = 1;
	game->screen_img = mlx_xpm_file_to_image(game->mlx, \
			"bonus/img/screen.xpm", &game->img_width, &game->img_height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, \
			"bonus/img/wall.xpm", &game->img_width, &game->img_height);
	game->player_img = mlx_xpm_file_to_image(game->mlx, \
			"bonus/img/player1.xpm", &game->img_width, &game->img_height);
	game->collect_img = mlx_xpm_file_to_image(game->mlx,
			"bonus/img/collectible.xpm", &game->img_width, &game->img_height);
	game->enemy_img = mlx_xpm_file_to_image(game->mlx,
			"bonus/img/enemy.xpm", &game->img_width, &game->img_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
			"bonus/img/exit.xpm", &game->img_width, &game->img_height);
	if (!game->screen_img || !game->wall_img || !game->player_img
		|| !game->collect_img || !game->enemy_img || !game->exit_img)
	{
		ft_printf("Invalid xpm image \n");
		exit (0);
	}
}

void	set_walls(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->wall_img, y * 64, x * 64);
}

int	main(int argc, char	**argv)
{
	t_game	game;
	int		i;

	i = 0;
	if (argc == 2)
	{
		game.map = get_map(argv[1], &game);
		if (game.map != NULL)
		{
			game.mlx = mlx_init();
			game.mlx_win = mlx_new_window(game.mlx, (game.width * 64), \
					(game.height * 64), "so_long");
			set_images(&game);
			put_images(&game);
			mlx_hook(game.mlx_win, 2, 0, key_hook, &game);
			mlx_hook(game.mlx_win, 17, 0, close_game, &game);
			mlx_loop_hook(game.mlx, loop_hook, &game);
			mlx_loop(game.mlx);
		}
	}
	return (0);
}
