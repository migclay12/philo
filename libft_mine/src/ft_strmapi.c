/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:58:03 by miggonza          #+#    #+#             */
/*   Updated: 2022/09/23 17:55:08 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	length;
	char	*recive;
	size_t	i;

	if (!s || !f)
		return (0);
	length = ft_strlen(s);
	recive = malloc(sizeof(char) * (length + 1));
	if (!recive)
		return (0);
	i = 0;
	while (i < length)
	{
		recive[i] = f(i, s[i]);
		i++;
	}
	recive[i] = '\0';
	return (recive);
}
