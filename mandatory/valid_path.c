/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:21:48 by hasserao          #+#    #+#             */
/*   Updated: 2022/12/27 23:17:34 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void find_cords(t_game *map)
{
	int i;
	int j;
	
	i = -1;
	while (map->map[++i]!=NULL)
	{
		j = -1;
		while(map->map[i][++j])
		{
			if (map->map[i][j] == 'P')
			{
				map->x_player = i;
				map->y_player = j;
			}
			if (map->map[i][j] == 'E')
			{
				map->x_exit = i;
				map->y_exit = j;
			}
		}
	}
}
int find_path (t_cords cords,char **map)
{
	if (cords.x_p == cords.x_e && cords.y_p == cords.y_e)
		return (1);
	if (map[cords.x_p][cords.y_p] == '1')
		return (0);
	map[cords.x_p][cords.y_p] = '1';
	if(find_path((t_cords){cords.x_p+1,cords.y_p,cords.x_e,cords.y_e},map))
		return (1);
	if(find_path((t_cords){cords.x_p - 1,cords.y_p,cords.x_e,cords.y_e},map))
		return (1);
	if(find_path((t_cords){cords.x_p,cords.y_p+1,cords.x_e,cords.y_e},map))
		return (1);
	if(find_path((t_cords){cords.x_p,cords.y_p-1,cords.x_e,cords.y_e},map))
		return (1);
	map[cords.x_p][cords.y_p] = '0';
	return (0);
}
int valid_path (t_game *game,char *file,int dst_x, int dst_y)
{
	char **map;
	map =read_map(file,game);
	find_cords(game);
	if (!find_path((t_cords) {game->x_player, game->y_player,dst_x, dst_y},map))
	{
		free_aray(map);
		return (0);
	}
	free_aray(map);
	return (1);
}
int check_path (t_game *map,char *file)
{
	int i;
	int j;
	
	map->n_exit = 0;
	i = -1;
	while (map->map[++i] != NULL)
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'E')
			{
				if (!valid_path(map,file,i,j))
					return (0);
				map->n_exit++;
			}
		}
	}
	if (!(map->n_exit == 1))
		return (0);
	return (1);
}
int check_collect (t_game *map,char *file)
{
	int i;
	int j;
	
	map->n_collect = 0;
	i = -1;
	while (map->map[++i] != NULL)
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'C')
			{
				if (!valid_path(map,file,i,j))
					return (0);
				map->n_collect++;
			}
		}
	}
	if (!(map->n_collect >= 1))
		return (0);
	return (1);
}