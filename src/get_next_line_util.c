/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:13:25 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/06 16:44:20 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*ft_get_line(char *static_text, int what)
{
	size_t	pos;
	char	*line;

	pos = ft_strpos(static_text, what);
	if (pos)
	{
		line = ft_substr(static_text, 0, pos);
		return (line);
	}
	else
		return (NULL);
}

char	*ft_strdup(char *str)
{
	char	*puntero;
	size_t	counter;
	size_t	len;

	counter = 0;
	len = ft_strlen(str);
	puntero = (char *)malloc(sizeof(char) * (len) + 1);
	if (puntero == NULL)
		return (NULL);
	while (counter < len)
	{
		puntero[counter] = str[counter];
		counter++;
	}
	puntero[counter] = '\0';
	return (puntero);
}

size_t	ft_strlen(char	*text)
{
	size_t	i;

	i = 0;
	if (!text)
		return (0);
	while (text[i])
		i++;
	return (i);
}

size_t	ft_strpos( char *s, int c)
{
	size_t	counter;

	counter = 0;
	while (s && s[counter] != '\0')
	{
		if (s[counter] == (unsigned char)c)
		{
			return (counter + 1);
		}
		counter++;
	}
	if (s[counter] == (unsigned char)c)
		return (counter + 1);
	return (0);
}

char	*free_vars(char *s1, char *s2)
{
	char	*back;

	back = ft_strjoin(s1, s2);
	free (s1);
	s1 = NULL;
	free(s2);
	s2 = NULL;
	return (back);
}
