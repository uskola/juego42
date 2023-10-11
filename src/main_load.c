/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:52:32 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/19 12:43:02 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	initial_data_load(t_data *data)
{
	data->res = PIXELS_CELLS;
	data->player.this_pos_x = data->p_st_p_x * PIXELS_CELLS;
	data->player.this_pos_y = data->p_st_p_y * PIXELS_CELLS;
	data->player.n_p_x = data->player.this_pos_x;
	data->player.n_p_y = data->player.this_pos_y;
	data->p_sc_p_x = data->p_st_p_x;
	data->p_sc_p_y = data->p_st_p_y;
	data->frames = 1;
	data->s_move_x = 0;
	data->s_move_y = 0;
	data->presed_keys = 0;
	data->finished = 0;
	data->you_win = 0;
	data->you_lost = 0;
	data->end_move = 0;
	data->rending = 1;
	data->animation = 0;
	data->pos_change_speed = 1;
	data->game_finish_time = 0;
}

int	check_collectionables(t_data *data)
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
			if (data->map[i][j] == 'C')
				counter++;
			j++;
		}
		i++;
		j = 0;
	}
	if (counter == 0)
	{
		ft_putstr("Error\n No collectable on map");
		exit(0);
	}
	return (counter);
}

int	load_file(t_data *data, int i)
{
	int		fd;
	char	*text;

	fd = open(data->argv_map, O_RDONLY);
	if (fd < 0)
		return (0);
	text = "a";
	while (text != NULL)
	{
		text = get_next_line(fd);
		if (!text)
			return (0);
		if (!check_map(data, text))
			return (-1);
		if (text[ft_strlen(text) - 1] == '\n')
			text[ft_strlen(text) - 1] = '\0';
		data->cols = ft_strlen(text);
		data->rows = i;
		file_to_map(data, i, text);
		i++;
		free(text);
	}
	close(fd);
	return (0);
}
