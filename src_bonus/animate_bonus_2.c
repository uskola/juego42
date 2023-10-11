/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_bonus2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:36:47 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/06 14:39:34 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

void	animate_help_lines(t_data *data)
{
	print_image_from_memory(data, data->background_pic, 0, 0);
	print_image_from_memory(data, data->player_pic, \
	data->p_sc_p_x, data->p_sc_p_y);
}

void	animate_finish(t_data *data)
{
	if (data->animation == 0)
	{
		if (data->player.this_pos_x / PIXELS_CELLS < WAIT_DOWN_CELLS)
			data->p_sc_p_x = data->player.this_pos_x;
		else
			data->p_sc_p_x = WAIT_DOWN_CELLS * PIXELS_CELLS;
		if (data->player.this_pos_y / PIXELS_CELLS < WAIT_RIGHT_CELLS)
			data->p_sc_p_y = data->player.this_pos_y;
		else
			data->p_sc_p_y = WAIT_RIGHT_CELLS * PIXELS_CELLS;
		print_image_from_memory(data, \
		witch_frame(1, data), data->p_sc_p_x, data->p_sc_p_y);
	}
}

void	animate_patch_lines(t_data *data, int x, int y)
{
	data->p_m.this_pos_x = 0;
	data->p_m.this_pos_y = 0;
	data->p_m.n_p_x = 0;
	data->p_m.n_p_y = 0;
	if (data->player.this_pos_y / PIXELS_CELLS >= WAIT_DOWN_CELLS)
		data->p_m.this_pos_x = data->player.this_pos_y \
	/ PIXELS_CELLS - WAIT_DOWN_CELLS;
	if (data->player.this_pos_x / PIXELS_CELLS >= WAIT_RIGHT_CELLS)
		data->p_m.this_pos_y = data->player.this_pos_x \
	/ PIXELS_CELLS - WAIT_RIGHT_CELLS;
	data->p_m.n_p_x = x + data->p_m.this_pos_x;
	data->p_m.n_p_y = y + data->p_m.this_pos_y ;
	if (data->p_m.n_p_x >= data->rows)
		data->p_m.n_p_x = data->rows;
	if (data->p_m.n_p_y >= data->cols)
		data->p_m.n_p_y = data->cols;
}

void	image_exit_patch(t_data *data, int x, int y)
{
	if (count_images(data, 'C') == 0)
		print_image_from_memory(data, data->exit2_pic, \
		y * PIXELS_CELLS, x * PIXELS_CELLS);
	else
		print_image_from_memory(data, data->exit_pic, \
		y * PIXELS_CELLS, x * PIXELS_CELLS);
}
