/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yigsahin <yigsahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:44:16 by yigsahin          #+#    #+#             */
/*   Updated: 2025/02/25 11:25:08 by yigsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_free(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
	return (NULL);
}

void	put_image(t_map *m, void *img, int x, int y)
{
	mlx_put_image_to_window(m->mlx, m->win, img, x, y);
}

void	change_exit(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->map_h)
	{
		j = 0;
		while (j < m->map_w)
		{
			if (m->map_arr[i][j] == 'E')
				put_image(m, m->open, j * m->i_w, i * m->i_h);
			j++;
		}
		i++;
	}
	return ;
}

void	print_steps(t_map *m)
{
	ft_printf("Steps: %d\n", m->steps);
}

void	update_player_image(t_map *m, int dx)
{
	if (dx == 0)
		put_image(m, m->plr, m->px * m->i_w, m->py * m->i_h);
	else if (dx == 1)
		put_image(m, m->plr, m->px * m->i_w, m->py * m->i_h);
	else if (dx == -1)
		put_image(m, m->pll, m->px * m->i_w, m->py * m->i_h);
}
