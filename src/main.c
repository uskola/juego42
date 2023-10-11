/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:39:34 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/21 13:58:31 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	render(t_data *data)
{	
	int	x;
	int	y;

	if (data->win_ptr == NULL)
		return (1);
	if (data->rending > 1000 && data->you_lost == 0 && data->you_win == 0)
	{	
		data->animation = 1;
		animate_background(data);
		if (data->player.this_pos_x / PIXELS_CELLS > 10)
			x = PIXELS_CELLS * 10;
		else
			x = data->player.this_pos_x ;
		if (data->player.this_pos_y / PIXELS_CELLS > 10)
			y = PIXELS_CELLS * 10;
		else
			y = data->player.this_pos_y ;
		print_image_from_memory(data, witch_frame(1, data), x, y);
		data->rending = 0;
		data->animation = 1;
	}
	data->rending ++;
	move_player(data);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	check_argc(&data, argc, argv);
	get_map_dimensions(&data);
	make_malloc(&data);
	data.actual_map = data.map;
	load_file(&data, 0);
	check_screen_resolution(&data);
	initial_data_load(&data);
	load_mlx(&data);
	check_closed_map(&data);
	check_map_chars(&data);
	load_screen_images(&data);
	check_collectionables(&data);
	check_valid_road(&data);
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, \
	data.window_height, data.window_width);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, \
	&data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, 17, 0, free_malloc, &data);
	mlx_key_hook(data.win_ptr, handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_window(data.mlx_ptr, data.img.mlx_img);
}
