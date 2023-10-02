/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <psotto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:54:19 by psotto-m          #+#    #+#             */
/*   Updated: 2023/04/20 10:16:25 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

# define BURGER "./assets/burger_floor.xpm"
# define EXIT "./assets/exit.xpm"
# define FLOOR "./assets/floor.xpm"
# define PLAYER "./assets/player.xpm"
# define PLAYER_EXIT "./assets/player_exit.xpm"
# define WALL "./assets/wall.xpm"

typedef enum keycodes
{
	ESC = 65307,
	W = 119,
	A = 97,
	S = 115,
	D = 100,
}	t_keys;

typedef struct s_game
{
	int		map_height;
	int		map_length;
	char	**map;
	char	**flood_fill;
	int		collectibles;
	int		player_check;
	int		player_location_height;
	int		player_location_length;
	int		exit_check;
	int		movements;
	void	*mlx_init;
	void	*game_window;
	void	*burger;
	void	*exit;
	void	*floor;
	void	*player;
	void	*player_exit;
	void	*wall;
}	t_game;

void	layout_errors(t_game *so_long, int flag);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
int		main(int ac, char **av);
void	map_sizer(char *str, t_game *so_long, int lines, int line_control);
void	symbol_control(char element, t_game *so_long);
void	struct_initiation(t_game *so_long);
void	check_map(char **map, t_game *so_long);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strchr(char *s, int c);
char	**map_creation(char *str, int height);
void	print_moves(t_game *so_long);
void	elements_control(t_game *so_long);
void	ber_check(char *str);
void	lets_play(t_game *so_long);
void	find_xpm(t_game *game);
void	render_map(t_game *so_long);
void	find_player(char **map, int height, t_game *so_long);
void	movement(t_game *so_long, char coord);
int		game_over(t_game *so_long);
void	free_map(t_game *so_long);
void	flood_fill(t_game *so_long);
int		handle_up_mov(t_game *so_long, int floor);
int		handle_down_mov(t_game *so_long, int floor);
int		handle_left_mov(t_game *so_long, int floor);
int		handle_right_mov(t_game *so_long, int floor);
void	handle_update_up(t_game *so_long);
void	handle_update_down(t_game *so_long);
void	handle_update_left(t_game *so_long);
void	handle_update_right(t_game *so_long);

#endif
