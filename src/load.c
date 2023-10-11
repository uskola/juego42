/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:39:00 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/06 15:39:03 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	load_screen_images_patch(t_data *data, int i, int j)
{
	char	*str;

	while (i < 4)
	{
		while (j < 4)
		{
			if (i == 0)
				str = ft_strdup_array("./sprites/witch-0-00.xpm", 16, 'l');
			if (i == 1)
				str = ft_strdup_array("./sprites/witch-0-00.xpm", 16, 'r');
			if (i == 2)
				str = ft_strdup_array("./sprites/witch-0-00.xpm", 16, 'u');
			if (i == 3)
				str = ft_strdup_array("./sprites/witch-0-00.xpm", 16, 'd');
			str[19] = j + 1 + '0';
			data->player_pic_a[i][j] = \
			mlx_xpm_file_to_image(data->mlx_ptr, str, &data->res, &data->res);
			free(str);
			j++;
		}
		i++;
		j = 0;
	}
}

void	load_screen_images(t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	while (i < 10)
	{
		str = ft_strdup_array("./fonts/0.xpm", 8, i + '0');
		data->numbers_pic[i] = mlx_xpm_file_to_image(data->mlx_ptr, \
		str, &data->res, &data->res);
		free (str);
		i++;
	}
	data->player_pic = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./sprites/witch-0-00.xpm", &data->res, &data->res);
	load_screen_images_patch(data, 0, 0);
	load_memory_images(data);
	data->move_user = 0;
}

void	file_to_map(t_data *data, int y, char *values)
{
	int	x;

	x = data->cols - 1;
	while (x >= 0)
	{
		data->map[y][x] = values[x];
		data->actual_map[y][x] = values[x];
		if (values[x] == 'P')
		{
			data->p_st_p_x = x;
			data->p_st_p_y = y;
		}
		x--;
	}
}

void	load_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		map_error ("1");
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
	data->window_width, data->window_height, "El gato volador");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		map_error ("1");
	}
}

void	get_map_dimensions(t_data *data)
{
	int		fd;
	char	*text;
	int		i;

	i = 0;
	fd = open(data->argv_map, O_RDONLY);
	if (fd < 0)
		map_error("File read error");
	text = "a";
	while (text != NULL)
	{
		text = get_next_line(fd);
		if (!text && i == 0)
			map_error("No content on file");
		if (!text)
			return ;
		if (text[ft_strlen(text) - 1] == '\n')
			text[ft_strlen(text) - 1] = '\0';
		data->cols = ft_strlen(text);
		i++;
		data->rows = i;
		free(text);
	}
	close (fd);
}
