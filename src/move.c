/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:54:03 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/06 15:54:05 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	finish_move(t_data *data)
{
	data->frames = 1;
	data->end_move = 0;
	data->actual_map[data->player.n_p_y / PIXELS_CELLS] \
	[data->player.n_p_x / PIXELS_CELLS] = 0;
	button_pressed(data);
}

void	change_player_position(t_data *data, int x, int y)
{
	is_game_finished(data, data->move_key);
	if (data->move_key != 1 + '0')
	{
		if (data->move_key != 'E')
		{
			data->player.n_p_x = data->player.this_pos_x \
			+ (1 * x * PIXELS_CELLS);
			data->player.n_p_y = data->player.this_pos_y \
			+ (1 * y * PIXELS_CELLS);
			data->p_st_p_x = data->p_st_p_x + y;
			data->p_st_p_y = data->p_st_p_y + x;
		}
	}
}

void	can_move(t_data *data, char key)
{
	if (key == 'l')
		data->move_key = data->actual_map[data->p_st_p_x][data->p_st_p_y - 1];
	if (key == 'l')
		change_player_position(data, -1, 0);
	if (key == 'r')
		data->move_key = data->actual_map[data->p_st_p_x][data->p_st_p_y + 1];
	if (key == 'r')
		change_player_position(data, 1, 0);
	if (key == 'd')
		data->move_key = data->actual_map[data->p_st_p_x + 1][data->p_st_p_y];
	if (key == 'd')
		change_player_position(data, 0, 1);
	if (key == 'u')
		data->move_key = data->actual_map[data->p_st_p_x - 1][data->p_st_p_y];
	if (key == 'u')
		change_player_position(data, 0, -1);
	finish_move(data);
}

void	move_player_2(t_data *data)
{
	if (data->player.n_p_x == data->player.this_pos_x && \
	data->player.n_p_y == data->player.this_pos_y)
	data->end_move = 1;
}

void	move_player(t_data *data)
{
	if (data->player.this_pos_x == data->player.n_p_x)
		data->s_move_x = 0;
	if (data->player.this_pos_y == data->player.n_p_y)
		data->s_move_y = 0;
	if (data->player.this_pos_x > data->player.n_p_x)
		data->s_move_x = -1 * data->pos_change_speed;
	if (data->player.this_pos_x < data->player.n_p_x)
		data->s_move_x = data->pos_change_speed;
	if (data->player.this_pos_y > data->player.n_p_y)
		data->s_move_y = -1 * data->pos_change_speed;
	if (data->player.this_pos_y < data->player.n_p_y)
		data->s_move_y = data->pos_change_speed;
	data->player.this_pos_x = data->player.this_pos_x + data->s_move_x;
	data->player.this_pos_y = data->player.this_pos_y + data->s_move_y;
	if (data->player.n_p_x - data->player.this_pos_x <= \
	data->pos_change_speed && data->player.n_p_x - \
	data->player.this_pos_x >= data->pos_change_speed * -1)
		data->player.this_pos_x = data->player.n_p_x;
	if (data->player.n_p_y - data->player.this_pos_y \
	<= data->pos_change_speed && data->player.n_p_y - \
	data->player.this_pos_y >= data->pos_change_speed * -1)
		data->player.this_pos_y = data->player.n_p_y;
	move_player_2(data);
	animate_background(data);
}
