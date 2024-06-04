/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:52:08 by miggonza          #+#    #+#             */
/*   Updated: 2022/09/28 10:48:58 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*set;
	size_t	i;

	set = (char *)s;
	i = 0;
	while (i < n)
	{
		if (set[i] == (char)c)
			return ((void *)(set + i));
		i++;
	}
	return (0);
}
