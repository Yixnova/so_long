/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yigsahin <yigsahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:11:30 by yigsahin          #+#    #+#             */
/*   Updated: 2025/03/18 10:41:59 by yigsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->map_h)
	{
		j = 0;
		while (j < m->map_w)
		{
			if (m->map_arr[i][j] == '1')
				put_image(m, m->wall, (j++) * m->i_w, i * m->i_h);
			else
			{
				put_image(m, m->i_sp, j * m->i_w, i * m->i_h);
				if (m->map_arr[i][j] == 'P')
					put_image(m, m->plr, j * m->i_w, i * m->i_h);
				else if (m->map_arr[i][j] == 'E')
					put_image(m, m->close, j * m->i_w, i * m->i_h);
				else if (m->map_arr[i][j] == 'C')
					put_image(m, m->item, j * m->i_w, i * m->i_h);
				j++;
			}
		}
		i++;
	}
}

int	key_hook(int key_code, t_map *m)
{
	if (key_code == KEY_UP)
		return (move(m, -1, 0));
	if (key_code == KEY_DOWN)
		return (move(m, 1, 0));
	if (key_code == KEY_LEFT)
		return (move(m, 0, -1));
	if (key_code == KEY_RIGHT)
		return (move(m, 0, 1));
	if (key_code == KEY_ESC)
		exit_hook(m);
	return (0);
}

void	images_struct(t_map *m)
{
	m->i_sp = mlx_xpm_file_to_image(m->mlx, "./imgs/s.xpm", &m->i_w, &m->i_h);
	m->wall = mlx_xpm_file_to_image(m->mlx, "./imgs/w.xpm", &m->i_w, &m->i_h);
	m->plr = mlx_xpm_file_to_image(m->mlx, "./imgs/pr.xpm", &m->i_w, &m->i_h);
	m->pll = mlx_xpm_file_to_image(m->mlx, "./imgs/pl.xpm", &m->i_w, &m->i_h);
	m->close = mlx_xpm_file_to_image(m->mlx, "./imgs/e.xpm", &m->i_w, &m->i_h);
	m->open = mlx_xpm_file_to_image(m->mlx, "./imgs/eo.xpm", &m->i_w, &m->i_h);
	m->item = mlx_xpm_file_to_image(m->mlx, "./imgs/c.xpm", &m->i_w, &m->i_h);
}

int	exit_hook(t_map *m)
{
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
	return (0);
}

int	main(int ac, char **av)
{
	t_map	m;
	int		fd;

	if (ac == 2)
	{
		ft_memset(&m, 0, sizeof(t_map));
		m.map_path = av[1];
		m.steps = 0;
		fd = open(m.map_path, O_RDONLY);
		if (fd == -1)
			exit(0);
		m.map_arr = map_process(fd, &m);
		close(fd);
		if (!is_map_valid(&m))
			return (exit_hook(&m));
		m.mlx = mlx_init();
		images_struct(&m);
		m.win = mlx_new_window(m.mlx, m.i_w * m.map_w,
				m.i_h * m.map_h, "so_long");
		draw_map(&m);
		mlx_play(&m);
		exit_hook(&m);
	}
	else
		ft_printf("Hata! Geçersiz Argüman!\n");
}
