/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:31:22 by hasserao          #+#    #+#             */
/*   Updated: 2022/12/28 17:31:26 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int check_file (char *file,t_game *map)
{
	map->fd = open(file, O_RDONLY);

	if (map->fd == -1)
		return (0);
	if(ft_strrchr(file, '.')== NULL || ft_strncmp(ft_strrchr(file, '.'), ".ber",4) !=0)
		return (0);
	else
		return (1);
}

int check_lines(t_game *map)
{
	int i;
	map->height = 0;
	map->width = 0;//number of columns
	i = 0;

	while (map->map[map->height]!=NULL)
	{
		while (map->map[map->height][map->width] !='\0')
			map->width++;
		map->height++;
	}
	while (i < map->width)
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			return(0);
		i++;
	}
	return (1);
}

int check_cols (t_game *map)
{
	int i;
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int check_rect (t_game *map)
{
	int i;
	i = 0;

	if (!map->map)
		return (0);
	while (map->map[i]!= NULL)
	{
		if (ft_strlen (map->map[i]) != ft_strlen(map->map[0]))
			return (0);
		i++;
	}
	return (1);
}

int check_char(t_game *map)
{
	int i;
	int j;

	map->n_player = 0;
	i = -1;
	while (map->map[++i] != NULL)
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '0'&& map->map[i][j] != 'P' && map->map[i][j] != 'C' && map->map[i][j] != 'E' && map->map[i][j] != 'X')
				return (0);
			if (map->map[i][j] == 'P')
				map->n_player++;
		}
	}
	if (!(map->n_player == 1))
		return (0);
	return (1);
}
