/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yigsahin <yigsahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:00:37 by yigsahin          #+#    #+#             */
/*   Updated: 2025/03/18 10:42:41 by yigsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_msg(t_map *m)
{
	ft_printf("Error! Map\n");
	if (m->i_sp)
		mlx_destroy_image(m->mlx, m->i_sp);
	if (m->wall)
		mlx_destroy_image(m->mlx, m->wall);
	if (m->plr)
		mlx_destroy_image(m->mlx, m->plr);
	if (m->pll)
		mlx_destroy_image(m->mlx, m->pll);
	if (m->close)
		mlx_destroy_image(m->mlx, m->close);
	if (m->open)
		mlx_destroy_image(m->mlx, m->open);
	if (m->item)
		mlx_destroy_image(m->mlx, m->item);
	if (m->win)
		mlx_destroy_window(m->mlx, m->win);
	if (m->map_arr)
		ft_free(m->map_arr);
	if (m->mlx)
	{
		#ifdef __linux__
			mlx_destroy_display(m->mlx);
		#endif
		free(m->mlx);
	}
	exit(0);
}

static int	is_rectangular(t_map *m)
{
	int		y;
	size_t	width;

	y = 0;
	width = ft_strlen(m->map_arr[0]);
	while (y < m->map_h)
	{
		if (ft_strlen(m->map_arr[y]) != width)
		{
			ft_printf("Hata\nMap eşit bir dikdörtgen değil.\n");
			exit_hook(m);
		}
		y++;
	}
	return (1);
}

static int	is_surrounded_by_walls(t_map *m)
{
	int	x;
	int	y;

	y = 0;
	while (y < m->map_h)
	{
		if (m->map_arr[y][0] != '1'
			|| m->map_arr[y][m->map_w - 1] != '1')
			return (0);
		y++;
	}
	x = 0;
	while (x < m->map_w)
	{
		if (m->map_arr[0][x] != '1'
			|| m->map_arr[m->map_h - 1][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	is_map_valid(t_map *m)
{
	if (!is_rectangular(m))
	{
		exit_hook(m);
		return (0);
	}
	if (!is_surrounded_by_walls(m))
	{
		ft_printf("Duvar! Hata!\n");
		exit_hook(m);
		return (0);
	}
	if (!is_map_playable(m))
	{
		exit_hook(m);
		return (0);
	}
	return (1);
}
