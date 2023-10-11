/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:47:10 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/15 14:19:58 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

int	enemy_move_time_left(t_data *data, int x, int y)
{
	if (data->map[x][y - 1] == '0' || (y - 1) == \
	data->player.this_pos_x / 64)
	{
		if (x == data->player.this_pos_y / 64 && y - 1 == \
		data->player.this_pos_x / 64)
			data->you_lost = 1;
		data->map[x][y - 1] = ENEMY_KEY;
		return (1);
	}
	else
		return (0);
}

int	enemy_move_time_right(t_data *data, int x, int y)
{
	if (data->map[x][y + 1] == '0' || (y + 1) == \
	data->player.this_pos_x / 64)
	{
		if (y + 1 == data->player.this_pos_x / 64 && x == \
		data->player.this_pos_y / 64)
			data->you_lost = 1;
		data->map[x][y + 1] = ENEMY_KEY;
		return (1);
	}
	else
		return (0);
}

int	enemy_move_time_up(t_data *data, int x, int y)
{
	if (data->map[x - 1][y] == '0' || (x - 1) == \
	data->player.this_pos_y / 64)
	{
		if (x - 1 == data->player.this_pos_y / 64 && y == \
		data->player.this_pos_x / 64)
			data->you_lost = 1;
		data->map[x - 1][y] = ENEMY_KEY;
		return (1);
	}
	else
		return (0);
}

int	enemy_move_time_down(t_data *data, int x, int y)
{
	if (data->map[x + 1][y] == '0' || (x + 1) == \
	data->player.this_pos_y / 64)
	{
		if (x + 1 == data->player.this_pos_y / 64 && y == \
		data->player.this_pos_x / 64)
			data->you_lost = 1;
			data->map[x + 1][y] = ENEMY_KEY;
		return (1);
	}
	else
		return (0);
}
