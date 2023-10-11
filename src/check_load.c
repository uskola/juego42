/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:52:38 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/21 14:58:14 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	check_map(t_data *data, char *text)
{
	int	line_size;

	if (text[ft_strlen(text) - 1] == '\n')
		text[ft_strlen(text) - 1] = '\0';
	line_size = ft_strlen(text);
	data->rows = data->rows + 1;
	if (data->cols != 0)
		if (data->cols != line_size)
			map_error("Incorrect rows/cols");
	if (data->cols > WINDOW_WIDTH_CELLS)
		map_error("Too big number of COLS");
	if (data->rows > WINDOW_HEIGHT_CELLS)
		map_error("Too big number of rows");
	data->cols = line_size;
	return (1);
}

int	check_closed_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->cols)
	{
		if (data->map[0][i] != 1 + '0')
			map_error("First row on map is not closed");
		if (data->map[data->rows][i] != 1 + '0')
			map_error("Last row on map is not closed");
		i++;
	}
	i = 0;
	while (i < data->rows -1)
	{
		if (data->map[i][0] != 1 + '0')
			map_error("First col on map is not closed");
		if (data->map[i][data->cols - 1] != 1 + '0')
			map_error("Last col on map is not closed");
		i++;
	}
	return (0);
}

int	check_char(t_data *data, char key)
{
	int	counter;
	int	i;
	int	j;

	i = 0;
	j = 0;
	counter = 0;
	while (i <= data->rows)
	{
		while (j < data->cols)
		{
			if (data->map[i][j] == key)
				counter++;
			j++;
		}
		i++;
		j = 0;
	}
	return (counter);
}

int	check_map_chars(t_data *data)
{
	int	counter;
	int	sum;

	sum = (data->rows + 1) * (data->cols);
	counter = check_char(data, 'E');
	sum -= counter;
	if (counter != 1)
		map_error("Exit char error");
	counter = check_char(data, 'P');
	sum -= counter;
	if (counter != 1)
		map_error("Player error");
	counter = check_char(data, 'C');
	sum -= counter;
	if (counter == 0)
		map_error("No Collectables in game");
	counter = check_char(data, '0');
	sum -= counter;
	counter = check_char(data, '1');
	sum -= counter;
	if (sum != 0)
		map_error("Extrange characters on map.");
	return (0);
}

int	check_argc(t_data *data, int argc, char *argv[])
{
	int	fd;
	int	i;

	if (argc == 1)
	{
		map_error("Please insert .ber file map path. \n\
./so_long \"maps/ghosts_basic.ber\"\n./so_long \"maps/island_basic.ber\"\n");
	}
	if (argc > 2)
		map_error("Too many argumensts.");
	if (argc == 2)
	{
		data->argv_map = argv[1];
		i = ft_strlen(data->argv_map);
		if (data->argv_map[i - 4] == '.' && data->argv_map[i - 3] == 'b' \
		&& data->argv_map[i - 2] == 'e' && data->argv_map[i - 1] == 'r')
		{
			fd = open(data->argv_map, O_RDONLY);
			if (fd < 0)
				map_error("Cant open map file");
		}
		else
			map_error("Map file extension must be \".ber\".");
	}
	return (0);
}
