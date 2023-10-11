/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:22:40 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/07 14:40:42 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

void	check_enemy_move1(t_data *data, int x, int y)
{
	int	pos_found;

	pos_found = enemy_move_time(data, x, y, LEFT);
	if (pos_found)
	{
		data->map[x][y] = '0';
		data->map[x][y - 1] = ENEMY_KEY;
	}
}

void	check_enemy_move2(t_data *data, int x, int y)
{
	int	pos_found;

	pos_found = enemy_move_time(data, x, y, RIGHT);
	if (pos_found)
	{
		data->map[x][y + 1] = ENEMY_KEY;
		data->map[x][y] = '0';
	}
}

void	check_enemy_move3(t_data *data, int x, int y)
{
	int	pos_found;

	pos_found = enemy_move_time(data, x, y, UP);
	if (pos_found)
	{
		data->map[x][y] = '0';
		data->map[x - 1][y] = ENEMY_KEY;
	}
}

void	check_enemy_move4(t_data *data, int x, int y)
{
	int	pos_found;

	pos_found = enemy_move_time(data, x, y, DOWN);
	if (pos_found)
	{
		data->map[x][y] = '0';
		data->map[x + 1][y] = ENEMY_KEY;
	}
}
