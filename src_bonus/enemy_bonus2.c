/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:50:40 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/07 16:25:23 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

int	change_enemy_position(t_data *data, int x, int y)
{
	is_game_enemy_end(data, x, y);
	return (0);
}

int	check_enemy(t_data *data)
{
	int	counter;
	int	i;
	int	j;

	if (data->enemy > 0)
		create_threads(data);
	i = 0;
	j = 0;
	counter = 0;
	while (i <= data->rows)
	{
		while (j < data->cols)
		{
			if (data->map[i][j] == ENEMY_KEY)
			{
				check_enemy_move(data, i, j);
				counter++;
			}
			j++;
		}
		i++;
		j = 0;
	}
	data->enemy = counter;
	return (counter);
}
