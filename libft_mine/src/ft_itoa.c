/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:19:55 by miggonza          #+#    #+#             */
/*   Updated: 2022/09/27 19:16:54 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_getlength(long int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long long	i;
	char		*recive;
	int			count;

	i = (long long)n;
	count = ft_getlength(i);
	recive = malloc(sizeof(char) * count + 1);
	if (!recive)
		return (NULL);
	recive[count] = '\0';
	if (i == 0)
		recive[0] = '0';
	if (i < 0)
	{
		i *= -1;
		recive[0] = '-';
	}
	while (i > 0)
	{
		recive[count - 1] = ((i % 10) + '0');
		i /= 10;
		count--;
	}
	return (recive);
}
