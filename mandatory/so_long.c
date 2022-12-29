/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:43:06 by hasserao          #+#    #+#             */
/*   Updated: 2022/12/29 14:54:44 by hasserao         ###   ########.fr       */
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

int	check_path(t_game *map, char *file)
{
	int	i;
	int	j;

	map->n_exit = 0;
	i = -1;
	while (map->map[++i] != NULL)
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'E')
			{
				if (!valid_path(map, file, i, j))
					return (0);
				map->n_exit++;
			}
		}
	}
	if (!(map->n_exit == 1))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		i;

	i = 0;
	if (argc == 2)
	{
		game.map = get_map(argv[1], &game);
		if (game.map != NULL )
		{
			game.mlx = mlx_init();
			game.mlx_win = mlx_new_window(game.mlx, (game.width * 64), \
				(game.height * 64), "so_long");
			set_images(&game);
			put_images(&game);
			mlx_hook(game.mlx_win, 2, 0, key_hook, &game);
			mlx_hook(game.mlx_win, 17, 0, close_game, &game);
			mlx_loop(game.mlx);
		}
	}
	return (0);
}
