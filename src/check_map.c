/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:12:09 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/21 14:02:33 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	check_map_finished(t_data *new_map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->rows - 1)
	{
		while (j < data->cols - 1)
		{
			if (new_map->map[i][j] != '1' && new_map->map[i][j] != '-' \
			&& new_map->map[i][j] != '0')
				map_error("cant finish map");
			j++;
		}
		j = 0;
		i++;
	}
	load_file(data, 0);
	return (1);
}

int	check_mark(t_data *data, t_data *map, int x, int y)
{
	int	changed;

	changed = 0;
	if (map->map[x][y] == '1' || map->map[x][y] == '-')
		return (0);
	if (map->map[x + 1][y] == '-' || map->map[x - 1][y] == '-')
		changed = 1;
	if (map->map[x][y -1] == '-' || map->map[x][y + 1] == '-')
		changed = 1;
	if (changed == 1)
	{
		if (data->map[x][y] == 'C')
			map->map[x][y] = '-';
		if (data->map[x][y] == 'E')
			map->map[x][y] = '-';
		if (data->map[x][y] == '0')
			map->map[x][y] = '-';
		if (data->map[x][y] == ENEMY_KEY)
			map->map[x][y] = '-';
	}
	return (changed);
}

int	check_valid_road(t_data *data)
{
	t_data	new_map;
	int		changed;

	new_map.map = data->map;
	data->j = 0;
	new_map.map[data->p_st_p_x][data->p_st_p_y] = '-';
	changed = 1;
	while (changed-- == 1)
	{
		data->i = 0;
		while (data->i < data->rows)
		{
			while (data->j < data->cols)
			{
				if (check_mark(data, &new_map, data->i, data->j))
					changed = 1;
				data->j++;
			}
			data->j = 0;
			data->i++;
		}
	}
	if (check_map_finished(&new_map, data))
		return (1);
	return (0);
}
