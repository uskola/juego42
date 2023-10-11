/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:38:54 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/15 14:22:19 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	button_pressed(t_data *data)
{
	char	*itoa_temp;

	data->animation = 0;
	data->presed_keys++;
	ft_putstr("\nMoves: ");
	itoa_temp = ft_itoa(data->presed_keys);
	ft_putstr(itoa_temp);
	free (itoa_temp);
	move_player(data);
}

//exit (0) because minilibx crash sometimes

void	handle_keypress_2(int keysym, t_data *data)
{
	data->s_move_x = 0;
	data->s_move_y = 0;
	if ((data->player.this_pos_x == data->player.n_p_x) && \
	(data->player.this_pos_y == data->player.n_p_y))
	{
		if ((keysym == 123 || keysym == 0) && data->p_st_p_x + 64 != 1)
			can_move(data, 'l');
		if ((keysym == 97 || keysym == 65361) && data->p_st_p_x + 64 != 1)
			can_move(data, 'l');
		if (keysym == 124 || keysym == 2 || keysym == 100 || keysym == 65363)
			can_move(data, 'r');
		if (keysym == 125 || keysym == 1 || keysym == 115 || keysym == 65364)
			can_move(data, 'd');
		if (keysym == 126 || keysym == 13 || keysym == 119 || keysym == 65362)
			can_move(data, 'u');
	}
}

void	wait_temp(t_data *data)
{
	int	i;

	i = 0;
	while (i < 30)
	{
	data->background_pic = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./textures/background1280x800.xpm", &data->res, &data->res);
	i++;
	}
	handle_keypress(12, data);
}

int	handle_keypress(int keysym, t_data *data)
{
	int	i;

	if (keysym == 69 || keysym == 65451)
		if (data->pos_change_speed < 100)
			data->pos_change_speed++;
	if (keysym == 78 || keysym == 65453)
		if (data->pos_change_speed > 1)
			data->pos_change_speed--;
	if (keysym == 12 || keysym == 53 || keysym == 113 || keysym == 65307)
	{
		data->finished = 1;
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		i = 0;
		while (i <= data->rows)
		{
			free (data->map[i]);
			i++;
		}
		free(data->map);
		exit (0);
	}
	handle_keypress_2(keysym, data);
	return (0);
}

void	check_screen_resolution(t_data *data)
{
	data->window_width = WINDOW_WIDTH_CELLS * PIXELS_CELLS + PANEL_WIDTH;
	data->window_height = WINDOW_HEIGHT_CELLS * PIXELS_CELLS;
}
