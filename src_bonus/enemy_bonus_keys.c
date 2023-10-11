/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:52:51 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/07 13:48:09 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

int	enemy_move_left(t_data *data, int x, int y)
{
	if (data->map[x][y - 1] == '0' || (y - 1) == \
	data->player.this_pos_x / 64)
	{
		if (x == data->player.this_pos_y / 64 && y - 1 == \
		data->player.this_pos_x / 64)
			data->you_lost = 1;
		return (1);
	}
	else
		return (0);
}
