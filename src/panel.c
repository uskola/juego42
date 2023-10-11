/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:54:16 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/06 15:54:19 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	print_panel2(t_data *data)
{
	print_desc(data, 'C');
	print_image_from_memory(data, data->object_pic, \
	data->window_width - 71, COLLECTIONABLES_IMAGE_HEIGHT);
	print_desc(data, 'E');
	print_image_from_memory(data, data->speed, \
	data->window_width - 71, VELOCIMETER_IMAGE_HEIGHT);
	print_desc(data, 'K');
	print_image_from_memory(data, data->walk_pic, \
	data->window_width - 87, STEPS_IMAGE_HEIGHT);
	print_desc(data, 'S');
}

void	print_panel(t_data *data)
{
	if (count_images(data, 'C') == 0)
		print_image_from_memory(data, data->exit2_pic, \
		data->window_width - 71, EXIT_IMAGE_HEIGHT);
	else
		print_image_from_memory(data, data->exit_pic, \
		data->window_width - 71, EXIT_IMAGE_HEIGHT);
	print_desc(data, ENEMY_KEY);
	if (data->actual_map[data->p_st_p_x - 1] \
	[data->p_st_p_y] != 1 + '0')
		print_image_from_memory(data, data->up_pic, \
		data->window_width - 65, UP_IMAGE_HEIGHT);
	if (data->actual_map[data->p_st_p_x] \
	[data->p_st_p_y - 1] != 1 + '0')
		print_image_from_memory(data, data->left_pic, \
		data->window_width - 85, LEFT_IMAGE_HEIGHT);
	if (data->actual_map[data->p_st_p_x] \
	[data->p_st_p_y + 1] != 1 + '0')
		print_image_from_memory(data, data->right_pic, \
		data->window_width - 48, RIGHT_IMAGE_HEIGHT);
	if (data->actual_map[data->p_st_p_x + 1] \
	[data->p_st_p_y] != 1 + '0')
		print_image_from_memory(data, data->down_pic, \
		data->window_width - 65, DOWN_IMAGE_HEIGHT);
	print_panel2(data);
}
