/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:40:03 by miggonza          #+#    #+#             */
/*   Updated: 2024/02/29 11:49:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_functions(va_list argument, char type)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_putchar_pf(va_arg(argument, int));
	else if (type == 's')
		count += ft_putstr_pf(va_arg(argument, char *));
	else if (type == 'p')
		count += ft_pointr(va_arg(argument, void *));
	else if (type == 'd' || type == 'i')
		count += ft_putnbr(va_arg(argument, int));
	else if (type == 'u')
		count += ft_putnbr_base(va_arg(argument, int), "0123456789");
	else if (type == 'x')
		count += ft_putnbr_base(va_arg(argument, int), "0123456789abcdef");
	else if (type == 'X')
		count += ft_putnbr_base(va_arg(argument, int), "0123456789ABCDEF");
	else if (type == '%')
		count += ft_putchar_pf('%');
	else
		count += ft_putstr_pf(va_arg(argument, char *));
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list	argument;
	int		i;
	int		list;

	i = 0;
	list = 0;
	va_start(argument, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			list += ft_functions(argument, format[i + 1]);
			i++;
		}
		else
			list += ft_putchar_pf(format[i]);
		i++;
	}
	return (list);
}
