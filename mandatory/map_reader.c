/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:04:54 by hasserao          #+#    #+#             */
/*   Updated: 2022/12/27 21:02:19 by hasserao         ###   ########.fr       */
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
	if (!check_char(map) || !check_path(map,file) || !check_collect (map,file))
	{
		free_map(map);
		return (ft_printf("Error\nInvalid map \n"),NULL);
	}
	return (map->map);
}

