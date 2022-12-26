/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:04:54 by hasserao          #+#    #+#             */
/*   Updated: 2022/12/26 15:39:09 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *file,t_game *map)
{
	char	*line;
	char	*lines;
	char	*holder; 
	char	**res;

	map->fd = open(file, O_RDONLY);
	if (!map->fd)
		return (NULL);
	lines = ft_strdup("");
	while (1)
	{
		line = get_next_line(map->fd);
		if (line == NULL)
			break ;
		map->height++;
		holder = lines;
		lines = ft_strjoin(lines, line);
		free(line);
		free(holder);
	}
	if (ft_strncmp(lines,"",2) == 0)
		return (free(lines), NULL);
	res = ft_split(lines, '\n');
	return (free(lines), res);
}

void free_aray(char **array)
{
	int i;
	
	i = 0;
	while (array[i] != NULL)
		free (array[i++]);
	free (array);
}

void	free_map(t_game *map)
{
	free_aray(map->map);
	// TODO: destroy mlx shit
	// map->map = NULL;
}

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

char **make_visited_array(int height, int width)
 {
	int i;
	
	i = -1;
	char **new_map = malloc((height + 1) * sizeof(char *));
	while (++i < height)
	{
		new_map[i] = malloc ((width + 1) * sizeof(char));
		ft_bzero(new_map[i],width + 1);
	}
	new_map[height] = NULL;
	return (new_map);
}

int find_path(t_game *map, int x_p, int y_p, char **visited,char target)
{
	 //static int c;
	
	if (x_p < 0 || y_p < 0 || x_p >= map->height || y_p >= map->width
			|| visited[x_p][y_p ] == '1' || map->map[x_p][y_p] == '1' )
		return (0);
	if (map->map[x_p][y_p] == target)
		return (1);
	visited[x_p][y_p] = '1';
	if(find_path(map, x_p + 1,y_p, visited,target))
		return (1);
	if(find_path(map, x_p - 1 ,y_p , visited,target))
		return (1);
	if(find_path(map, x_p,y_p + 1, visited,target))
		return (1);
	if(find_path(map, x_p ,y_p - 1, visited,target))
		return (1);
	return (0);
}

int valid_path (t_game *map)
{
	find_cords(map);
	char **visited = make_visited_array(map->height, map->width);
	if (!find_path(map, map->x_player,map->y_player, visited,'E'))
	{
		free_map(map);
		free_aray(visited);
		return (0);
	}
	free_aray(visited);
	return (1);
}
char **get_map(char *file,t_game *map)
{
	if (!check_file(file,map))
		return (ft_printf("Error\nfile is invalid or may not exist\n"),NULL);
	map->map = read_map(file,map);
	if (!map->map)
		return (ft_printf("Error\nMap is empty\n"),NULL);
	if (!check_rect(map))
	{
		free_map(map);
		return(ft_printf("Error\nMap is not rectangular\n"),NULL);
	}
	if (!check_lines(map) || !check_cols (map))
	{
		free_map(map);
		return (ft_printf("Error\nMap not closed by walls\n"),NULL);
	}
	if (!check_char(map))
	{
		free_map(map);
		return (ft_printf("Error\nWrong characters or duplicates (exit/start)\n"),NULL);
	}
	if (!valid_path(map))
		return (ft_printf("Error\nThe is no valid path in the map\n"),NULL);
	return (map->map);
}

