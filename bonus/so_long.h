/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:08:58 by hasserao          #+#    #+#             */
/*   Updated: 2022/12/24 15:42:53 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# define K_esc 53
# define K_Q 12
# define K_W 13
# define K_S 1
# define K_A 0
# define K_D 2
# define K_UP 126
# define K_DOWN 125
# define K_LEFT 123
# define K_RIGHT 124

typedef struct s_game
{
    int     fd;
    char    **map;
    int     width;
    int     height;
	int		n_player;
	int		n_exit;
	int		n_collect;
    int     x_player;
    int     y_player;
    int     x_exit;
    int     y_exit;
    void    *mlx;
    void    *mlx_win;
	void	*img;
    int		img_width;
	int		img_height;
	void	*screen_img;
	void	*wall_img;
	void	*player_img;
	void	*enemy_img;
	void	*exit_img;
	void	*collect_img;
	int     movement;
    int     finish;
    
}               t_game;

int check_file (char *file,t_game *map);
char	**read_map(char *file,t_game *map);
void	free_map(t_game *map);
int check_lines(t_game *map);
char **get_map(char *file,t_game *map);
int check_cols (t_game *map);
int check_rect (t_game *map);
int check_char(t_game *map);
void find_cords(t_game *map);
int valid_path (t_game *map);
void set_images (t_game *game);
void put_images(t_game *game);
int key_hook(int keycode, t_game *game);
int close_game(t_game *game);
void kill_player(t_game *game);
void update_player(t_game *game,int keycode);
void kill_player(t_game *game);
void display_score(t_game *game);
#endif