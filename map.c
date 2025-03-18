/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yigsahin <yigsahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:10:32 by yigsahin          #+#    #+#             */
/*   Updated: 2025/02/26 09:09:12 by yigsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_gnl(t_map *m, char **line, char **map_str, int fd)
{
	char	*tmp;
	char	*new_line;

	*map_str = ft_strdup(*line);
	free(*line);
	*line = get_next_line(fd);
	while (*line)
	{
		tmp = *map_str;
		new_line = ft_strjoin(tmp, *line);
		free(tmp);
		free(*line);
		*map_str = new_line;
		*line = get_next_line(fd);
		m->map_h++;
	}
}

static int	checkcount(t_map *m)
{
	if (m->player_c != 1 || m->item_c < 1 || m->exit_c != 1)
	{
		ft_printf("Hata! Eksik veya fazla karakter.\n");
		exit_hook(m);
	}
	return (0);
}

static int	check_map(t_map *m)
{
	int	i;
	int	j;

	i = -1;
	while (++i < m->map_h)
	{
		j = -1;
		while (++j < m->map_w)
		{
			if (!ft_strchr(MAP_CHAR, m->map_arr[i][j]))
				check_map_msg(m);
			if (m->map_arr[i][j] == 'P')
			{	
				m->px = j;
				m->py = i;
				m->player_c++;
			}
			else if (m->map_arr[i][j] == 'C')
				m->item_c++;
			else if (m->map_arr[i][j] == 'E')
				m->exit_c++;
		}
	}
	checkcount(m);
	return (0);
}

static void	check_ber(t_map *m)
{
	char	*str;

	str = ft_substr(m->map_path, ft_strlen(m->map_path) - 4, 4);
	if (ft_strncmp(str, ".ber", 4) != 0)
	{
		ft_printf("Error! '.ber'\n");
		free(str);
		exit_hook(m);
	}
	free(str);
}

char	**map_process(int fd, t_map *m)
{
	char	*line;
	char	*map_str;

	m->player_c = 0;
	m->item_c = 0;
	m->exit_c = 0;
	check_ber(m);
	line = get_next_line(fd);
	if (!line)
		exit_hook(m);
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	m->map_w = ft_strlen(line) - 1;
	m->map_h = 1;
	ft_gnl(m, &line, &map_str, fd);
	m->map_arr = ft_split(map_str, '\n');
	free(map_str);
	check_map(m);
	return (m->map_arr);
}
