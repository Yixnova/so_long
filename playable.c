/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yigsahin <yigsahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:44:06 by yigsahin          #+#    #+#             */
/*   Updated: 2025/02/26 09:11:53 by yigsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill(char **map, int y, int x, t_map *m)
{
	if (y < 0 || x < 0 || y >= m->map_h || x >= m->map_w)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	if (map[y][x] == 'C')
		m->citem++;
	if (map[y][x] == 'E')
	{
		m->cexit = 1;
		return ;
	}
	map[y][x] = 'X';
	fill(map, y + 1, x, m);
	fill(map, y - 1, x, m);
	fill(map, y, x + 1, m);
	fill(map, y, x - 1, m);
}

static void	free_map_copy(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static char	**copy_map(t_map *game)
{
	int		i;
	char	**copy;

	i = 0;
	copy = malloc(sizeof(char *) * (game->map_h + 1));
	if (!copy)
		return (NULL);
	while (i < game->map_h)
	{
		copy[i] = ft_strdup(game->map_arr[i]);
		if (!copy[i])
		{
			free_map_copy(copy, i);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	is_map_playable(t_map *m)
{
	char	**map_copy;

	m->citem = 0;
	m->cexit = 0;
	map_copy = copy_map(m);
	if (!map_copy)
		return (0);
	fill(map_copy, m->py, m->px, m);
	free_map_copy(map_copy, m->map_h);
	if (m->citem != m->item_c)
	{
		ft_printf("Hata!\nTüm Item toplanabilir değil!\n");
		return (0);
	}
	if (m->cexit == 0)
	{
		ft_printf("Hata!\nExit!\n");
		return (0);
	}
	return (1);
}
