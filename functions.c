/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:40:42 by miggonza          #+#    #+#             */
/*   Updated: 2024/06/04 18:40:42 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	temp = (unsigned char *)b;
	while (i < len)
		temp[i++] = (unsigned char)c;
	return (b);
}

int	ft_atoi(const char *str)
{
	int				c;
	int				minus;
	long long int	recive;

	c = 0;
	minus = 1;
	recive = 0;
	while (str[c] == ' ' || (str[c] <= '\r' && str[c] >= '\t'))
		c++;
	if (str[c] == '+' || str[c] == '-')
	{
		if (str[c++] == '-')
			minus *= -1;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		recive = ((str[c] - '0') + (recive * 10));
		c++;
	}
	return (recive * minus);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
