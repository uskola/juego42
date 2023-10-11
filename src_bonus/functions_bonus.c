/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:45:59 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/21 14:51:15 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

void	is_game_finished(t_data *data, char value)
{
	if (value == ENEMY_KEY && data->finished == 0)
	{
		data->you_lost = 1;
		print_image_from_memory(data, data->lost_pic, 0, 0);
	}
	if (value == 'E' && data->finished == 1)
	{
		data->you_win = 1;
		print_image_from_memory(data, data->win_pic, 0, 0);
	}
	if (count_images(data, 'C') == 0)
		data->finished = 1;
}

void	time_exit(t_data *data)
{
	int	i;

	data->game_finish_time++;
	i = 0;
	while (i < 10)
	{
		if (data->you_win == 1)
		{
			data->win_pic = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./textures/win.xpm", &data->res, &data->res);
			print_image_from_memory(data, data->win_pic, 0, 0);
		}
		if (data->you_lost == 1)
		{
			data->lost_pic = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./textures/lost.xpm", &data->res, &data->res);
			print_image_from_memory(data, data->lost_pic, 0, 0);
		}
		i++;
	}
	if (data->game_finish_time > 15)
		handle_keypress(12, data);
	return ;
}

void	animate_background(t_data *data)
{
	int	x;
	int	y;

	if (data->you_win == 1 || data->you_lost == 1)
	{
		time_exit(data);
		return ;
	}
	print_image_from_memory(data, data->background_pic, 0, 0);
	print_image_from_memory(data, data->player_pic, \
	data->p_sc_p_x, data->p_sc_p_y);
	x = 0;
	y = 0;
	while (data->rows >= x && x <= WINDOW_HEIGHT_CELLS)
	{
		while (data->cols > y && y < WINDOW_WIDTH_CELLS)
		{
			animate_array_images (data, x, y);
			y++;
		}
		y = 0;
		x++;
	}
	animate_finish(data);
}
