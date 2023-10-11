/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:53:51 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/06 15:53:53 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup_array(char *str, int pos, char number)
{
	char	*pointer;
	int		counter;
	int		len;

	counter = 0;
	len = ft_strlen(str);
	pointer = (char *)malloc(sizeof(char) * (len) + 1);
	if (pointer == NULL)
		return (NULL);
	while (counter < len)
	{
		if (counter == pos)
			pointer[counter] = number;
		else
			pointer[counter] = str[counter];
		counter++;
	}
	pointer[counter] = '\0';
	return (pointer);
}

void	make_malloc(t_data *data)
{
	int		i;

	i = 0;
	data->map = (char **)malloc((data->rows + 1) * sizeof(char *));
	while (i < data->rows)
	{
		data->map[i] = (char *)malloc((data->cols + 1) * sizeof(char ));
		i++;
	}
}

void	load_memory_images(t_data *data)
{
	data->wall_pic = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./textures/baldosa.xpm", &data->res, &data->res);
	data->object_pic = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./textures/cat.xpm", &data->res, &data->res);
	data->exit_pic = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./textures/candado.xpm", &data->res, &data->res);
	data->exit2_pic = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./textures/bruja.xpm", &data->res, &data->res);
	data->free_pic = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./textures/black.xpm", &data->res, &data->res);
	data->left_pic = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./textures/left.xpm", &data->res, &data->res);
	data->right_pic = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./textures/right.xpm", &data->res, &data->res);
	load_memory_images2(data);
}

void	load_memory_images2(t_data *data)
{
	data->down_pic = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./textures/down.xpm", &data->res, &data->res);
	data->up_pic = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./textures/up.xpm", &data->res, &data->res);
	data->end_pic = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./textures/end.xpm", &data->res, &data->res);
	data->speed = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./textures/speed.xpm", &data->res, &data->res);
	data->walk_pic = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./textures/walk.xpm", &data->res, &data->res);
	data->lost_pic = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./textures/lost.xpm", &data->res, &data->res);
	data->win_pic = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./textures/win.xpm", &data->res, &data->res);
	data->background_pic = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./textures/background1280x800.xpm", &data->res, &data->res);
}

int	free_malloc(t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->rows)
	{
		free (data->map[i]);
		i++;
	}
	free(data->map);
	exit (0);
	return (0);
}
