/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yigsahin <yigsahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:41:13 by yigsahin          #+#    #+#             */
/*   Updated: 2025/03/18 10:44:33 by yigsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "lib/libft.h"
# include <fcntl.h>

# ifdef __APPLE__
#  include "minilibx-mac/mlx.h"
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_DOWN 125
#  define KEY_UP 126
#  define KEY_ESC 53
# else
#  include "minilibx-linux/mlx.h"
#  define KEY_LEFT 97
#  define KEY_RIGHT 100
#  define KEY_DOWN 115
#  define KEY_UP 119
#  define KEY_ESC 65307
# endif

# define MAP_CHAR "01CEP"

typedef struct s_map
{
	char	**map_arr;
	char	*map_path;
	int		map_w;
	int		map_h;
	int		player_c;
	int		item_c;
	int		exit_c;
	int		px;
	int		py;
	int		steps;
	int		i_w;
	int		i_h;
	int		citem;
	int		cexit;
	void	*i_sp;
	void	*mlx;
	void	*win;
	void	*wall;
	void	*plr;
	void	*pll;
	void	*close;
	void	*open;
	void	*item;
} t_map;

int		key_hook(int key_code, t_map *m);
int		exit_hook(t_map *m);
void	*ft_free(char **res);
void	put_image(t_map *m, void *img, int x, int y);
void	change_exit(t_map *m);
int		move(t_map *m, int dy, int dx);
void	move_empty(t_map *m, int dy, int dx);
void	move_col(t_map *m, int dy, int dx);
void	move_exit(t_map *m);
void	print_steps(t_map *m);
void	update_player_image(t_map *m, int dx);
char	**map_process(int fd, t_map *m);
void	draw_map(t_map *m);
int		is_map_valid(t_map *game);
int		is_map_playable(t_map *game);
void	images_struct(t_map *m);
void	mlx_play(t_map *m);
void	check_map_msg(t_map *m);

#endif
