/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line      .h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:12:13 by auskola-          #+#    #+#             */
/*   Updated: 2023/08/06 17:51:26 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# elif BUFFER_SIZE > 100000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

# include	<fcntl.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<string.h>
# include   <stdio.h>

char	*ft_strdup(char *str);
char	*get_next_line(int fd);
char	*update_static(char *static_text);
char	*ft_get_line(char *static_text, int what);
char	*ft_substr(char *old_string, unsigned int start, size_t len);
char	*read_data(int fd, char *static_text );
size_t	ft_strpos(char *s, int c);
size_t	ft_strlen(char	*text);
char	*ft_strjoin(char *s1, char *s2);
char	*free_vars(char *s1, char *s2);

#endif
