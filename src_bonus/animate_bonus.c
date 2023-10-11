/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:41:21 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/15 13:52:52 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

void	animate_array_images2(t_data *data)
{
	data->p_st_p_x = data->p_m.n_p_x ;
	data->p_st_p_y = data->p_m.n_p_y;
	print_image_from_memory(data, data->player_pic, \
	data->p_st_p_x * 64, data->p_st_p_y * 64);
	data->actual_map[data->p_m.n_p_x][data->p_m.n_p_y] = 0;
}

void	animate_array_images3(t_data *data, int x, int y)
{
	if (count_images(data, 'C') == 0)
		print_image_from_memory(data, data->exit2_pic, \
		y * PIXELS_CELLS, x * PIXELS_CELLS);
	else
		print_image_from_memory(data, data->exit_pic, \
		y * PIXELS_CELLS, x * PIXELS_CELLS);
}

void	animate_array_images(t_data *data, int x, int y)
{
	animate_patch_lines(data, x, y);
	if (data->actual_map[data->p_m.n_p_x][data->p_m.n_p_y] == '0')
		print_image_from_memory(data, data->free_pic, \
		y * PIXELS_CELLS, x * PIXELS_CELLS);
	else if (data->actual_map[data->p_m.n_p_x][data->p_m.n_p_y] == '1')
		print_image_from_memory(data, data->wall_pic, \
		y * PIXELS_CELLS, x * PIXELS_CELLS);
	else if (data->actual_map[data->p_m.n_p_x][data->p_m.n_p_y] == 'C')
		print_image_from_memory(data, \
		data->object_pic, y * PIXELS_CELLS, x * PIXELS_CELLS);
	else if (data->actual_map[data->p_m.n_p_x][data->p_m.n_p_y] == 'P')
		animate_array_images2(data);
	else if (data->actual_map[data->p_m.n_p_x][data->p_m.n_p_y] == 'E')
		animate_array_images3(data, x, y);
	else if (data->actual_map[data->p_m.n_p_x][data->p_m.n_p_y] == ENEMY_KEY)
	{
		if (count_images(data, 'C') == 0)
			print_image_from_memory(data, data->enemy2_pic, \
			y * PIXELS_CELLS, x * PIXELS_CELLS);
		else
			print_image_from_memory(data, data->enemy_pic, \
			y * PIXELS_CELLS, x * PIXELS_CELLS);
	}
}
