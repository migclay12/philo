/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:51:40 by miggonza          #+#    #+#             */
/*   Updated: 2022/09/13 15:51:43 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*count1;
	unsigned char	*count2;
	size_t			i;

	count1 = (unsigned char *)s1;
	count2 = (unsigned char *)s2;
	i = 0;
	while ((count1[i] != '\0' || count2[i] != '\0') && i < n)
	{
		if (count1[i] != count2[i])
			return (count1[i] - count2[i]);
		i++;
	}
	return (0);
}
