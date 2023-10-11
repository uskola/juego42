/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:21:09 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/15 14:20:56 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

void	is_game_enemy_end(t_data *data, int x, int y)
{
	if (data->map[x][y] == 'P' && data->finished == 0)
		data->you_lost = 1;
}

int	enemy_move_time(t_data *data, int x, int y, int key)
{
	if (key == LEFT)
	{
		if (enemy_move_time_left(data, x, y))
			return (1);
	}
	if (key == RIGHT)
	{
		if (enemy_move_time_right(data, x, y))
			return (1);
	}
	if (key == DOWN)
	{
		if (enemy_move_time_down(data, x, y))
			return (1);
	}
	if (key == UP)
	{
		if (enemy_move_time_up(data, x, y))
			return (1);
	}
	return (0);
}

void	check_enemy_move(t_data *data, int x, int y)
{
	int	pos_found;

	pos_found = 0;
	if (data->player.this_pos_x / 64 < y && pos_found == 0)
	{
		pos_found = enemy_move_time(data, x, y, LEFT);
	}
	if (data->player.this_pos_x / 64 > y && pos_found == 0)
	{
		pos_found = enemy_move_time(data, x, y, RIGHT);
	}
	if (data->player.this_pos_y / 64 < x && pos_found == 0)
	{
		pos_found = enemy_move_time(data, x, y, UP);
	}
	if (data->player.this_pos_y / 64 > x && pos_found == 0)
		pos_found = enemy_move_time(data, x, y, DOWN);
	if (pos_found)
		data->map[x][y] = '0';
	if (data->map[x][y] == 'P' && data->finished == 0)
		data->you_lost = 1;
}

int	move_enemy_time(t_data *data, int x, int y)
{
	int	i;
	int	wolf_speed;

	i = 0;
	wolf_speed = 600000;
	wolf_speed = wolf_speed - 3000 * data->pos_change_speed;
	usleep(wolf_speed);
	data->pos_change_speed++;
	exit (0);
	i++;
	return (x + y);
}

void	*move_enemy(void *enemy_data)
{
	int		i;
	t_data	*data;

	data = (t_data *)enemy_data;
	i = 0;
	while (!data->finished)
	{
		usleep(1000000);
		data->pos_change_speed++;
		check_enemy_pos(data);
		i++;
	}
	return (NULL);
}
//	pthread_join(data->pthread_enemy, NULL);
