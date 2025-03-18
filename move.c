/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yigsahin <yigsahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:45:58 by yigsahin          #+#    #+#             */
/*   Updated: 2025/02/25 17:54:54 by yigsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_play(t_map *m)
{
	mlx_hook(m->win, 2, 1, key_hook, m);
	mlx_hook(m->win, 17, 0, exit_hook, m);
	mlx_loop(m->mlx);
}

int	move(t_map *m, int dy, int dx)
{
	if (m->map_arr[m->py + dy][m->px + dx] == '1')
		return (1);
	if (m->map_arr[m->py + dy][m->px + dx] == '0')
		move_empty(m, dy, dx);
	else if (m->map_arr[m->py + dy][m->px + dx] == 'C')
		move_col(m, dy, dx);
	else if (m->map_arr[m->py + dy][m->px + dx] == 'E')
		move_exit(m);
	return (0);
}

void	move_empty(t_map *m, int dy, int dx)
{
	put_image(m, m->i_sp, m->px * m->i_w, m->py * m->i_h);
	m->map_arr[m->py][m->px] = '0';
	m->px += dx;
	m->py += dy;
	m->map_arr[m->py][m->px] = 'P';
	m->steps++;
	print_steps(m);
	update_player_image(m, dx);
}

void	move_col(t_map *m, int dy, int dx)
{
	move_empty(m, dy, dx);
	m->item_c--;
	if (m->item_c == 0)
		change_exit(m);
}

void	move_exit(t_map *m)
{
	if (m->item_c == 0)
	{
		m->steps++;
		print_steps(m);
		ft_putstr_fd("You win!\n", 1);
		exit_hook(m);
	}
	else
	{
		ft_putstr_fd("You need to collect all items before exiting.\n", 1);
	}
}
