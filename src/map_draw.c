/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:52:49 by auskola-          #+#    #+#             */
/*   Updated: 2023/08/08 10:52:50 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	print_text_on_screen(t_data *data, char *text, int x, int y)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, x, y, 0x000000, text);
}

void	print_image_from_memory(t_data *data, t_img *image, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, image, x, y);
}

void	print_image_on_screen(t_data *data, char *image_filename, int x, int y)
{
	data->background_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	image_filename, &data->res, &data->res);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr \
	, data->background_img, x, y);
}
