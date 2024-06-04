/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:07:57 by miggonza          #+#    #+#             */
/*   Updated: 2022/09/13 16:07:58 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
		if (recive > 2147483647 && minus == 1)
			return (-1);
		if (recive > 2147483648 && minus == -1)
			return (0);
	}
	return (recive * minus);
}
