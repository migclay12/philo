/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:13:56 by miggonza          #+#    #+#             */
/*   Updated: 2022/09/28 10:29:04 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	leng;

	leng = ft_strlen(s);
	while (leng >= 0)
	{
		if (s[leng] == (char)c)
			return ((char *)&s[leng]);
		leng--;
	}
	return (NULL);
}
