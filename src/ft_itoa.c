/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:36:42 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/06 15:38:29 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	characters(long n)
{
	int	counter;

	counter = 0;
	if (n < 0)
	{
		counter++;
		n = n * -1;
	}
	if (n == 0)
		return (1);
	while ((n / 10) > 0)
	{
		n = n / 10;
		counter ++;
	}
	return (counter + 1);
}

char	*convert_str(char *str, long n, int numbers, int counter)
{	
	int	character;

	str[numbers] = '\0';
	if (numbers == 1)
	{
		str[0] = n + '0';
		return (str);
	}
	counter = 0;
	if (n < 0)
	{
		str[0] = '-';
		counter = 1;
		n = (n * -1);
	}
	counter = 1;
	while (counter <= (numbers) && n > 0)
	{
		character = n % 10;
		n = n / 10;
		str[numbers - counter] = character + '0';
		counter ++;
	}
	return (str);
}

char	*ft_itoa(int valor)
{
	int		strings;
	char	*str;

	strings = characters(valor);
	str = (char *)malloc(sizeof(char) * (strings) +1);
	if (!str)
		return (NULL);
	str = convert_str(str, valor, strings, 0);
	return (str);
}
