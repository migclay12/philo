/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:16:43 by miggonza          #+#    #+#             */
/*   Updated: 2024/02/29 11:50:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putnbr(int nbr)
{
	long int	number;
	static int	count;

	number = (long long)nbr;
	count = 0;
	if (number < 0)
	{
		ft_putchar_pf('-');
		number *= -1;
	}
	if (number > 9)
		ft_putnbr(number / 10);
	count++;
	ft_putchar_pf(number % 10 + 48);
	if (nbr < 0)
		count++;
	return (count);
}

int	ft_putnbr_base(unsigned long int nbr, char *base)
{
	static int	count;
	long int	number;

	number = (unsigned int)nbr;
	count = 0;
	if (number >= ft_strlen_pf(base))
	{
		ft_putnbr_base(number / ft_strlen_pf(base), base);
		number = number % ft_strlen_pf(base);
	}
	count++;
	ft_putchar_pf(base[number]);
	return (count);
}

int	ft_converthex(size_t nbr)
{
	char		*base;
	static int	count;

	count = 0;
	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_converthex(nbr / 16);
		nbr = nbr % 16;
	}
	count++;
	ft_putchar_pf(base[nbr]);
	return (count);
}

int	ft_pointr(void *nbr)
{
	int		count;
	size_t	number;

	count = 0;
	number = (size_t)nbr;
	count = ft_strlen_pf("0x");
	count += ft_converthex(number);
	return (count);
}
