/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:10:42 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/07 16:25:42 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	res = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res || !s1 || !s2)
	{
		free(res);
		return (NULL);
	}
	while (*(s1 + i) != 0)
	{
		*(res + i) = *(s1 + i);
		i++;
	}
	j = 0;
	while (*(s2 + j) != 0)
	{
		*(res + i) = *(s2 + j);
		i++;
		j++;
	}
	*(res + ft_strlen(s1) + ft_strlen(s2)) = 0;
	return (res);
}

char	*read_data(int fd, char *static_text )
{
	char	*buffer;
	size_t	pos;
	size_t	readed;

	pos = ft_strpos(static_text, '\n');
	while (pos == 0)
	{
		buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		readed = read (fd, buffer, BUFFER_SIZE);
		buffer[readed] = '\0';
		if (readed)
		{
			static_text = free_vars(static_text, buffer);
			pos = ft_strpos(static_text, '\n');
		}
		else
		{
			free (buffer);
			if (ft_strlen(static_text) > 0)
				return (static_text);
			free(static_text);
			return (NULL);
		}
	}
	return (static_text);
}

char	*ft_substr(char *old_string, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	counter;

	if (!old_string)
		return ("");
	else if (ft_strlen(old_string) < start)
		return ("");
	if (len > (ft_strlen(old_string) - start))
		sub_str = (char *)malloc(sizeof(char) * \
			(ft_strlen(old_string) - start) + 1);
	else
		sub_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub_str || (ft_strlen(old_string) < start) || (len == 0))
	{
		free(sub_str);
		return (ft_strdup(""));
	}
	counter = 0;
	while ((counter < len) && (counter < ft_strlen(old_string) - start))
	{
		sub_str[counter] = old_string[start + counter];
		counter++;
	}
	sub_str[counter] = '\0';
	return (sub_str);
}

char	*update_static(char *static_text)
{
	size_t	pos;
	char	*tmp;

	pos = ft_strpos(static_text, '\n');
	tmp = static_text;
	if (pos)
		static_text = ft_substr(static_text, pos, \
			ft_strlen (static_text) - pos);
	free(tmp);
	return (static_text);
}

char	*get_next_line(int fd)
{
	static char	*static_text[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (read(fd, 0, 0) < 0)
		return (free(static_text[fd]), static_text[fd] = NULL, NULL);
	if (!static_text[fd])
		static_text[fd] = ft_strdup("");
	static_text[fd] = read_data(fd, static_text[fd]);
	if (ft_strlen(static_text[fd]) > 0)
	{
		line = ft_get_line(static_text[fd], (int ) '\n' );
		if (line != NULL)
			static_text[fd] = update_static(static_text[fd]);
		else
		{
			line = ft_get_line(static_text[fd], (int ) '\0' );
			*static_text[fd] = '\0';
		}
		return (line);
	}
	else
		free(static_text[fd]);
	return (NULL);
}
