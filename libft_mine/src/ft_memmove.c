/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:01:43 by miggonza          #+#    #+#             */
/*   Updated: 2022/09/20 16:01:45 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	char		*dstl;
	const char	*srcl;

	d = dst;
	s = src;
	dstl = d + (len - 1);
	srcl = s + (len - 1);
	if (*d == '\0' && *s == '\0')
		return (NULL);
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		while (len--)
			*dstl-- = *srcl--;
	}
	return (dst);
}
