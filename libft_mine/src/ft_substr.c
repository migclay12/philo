/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:36:52 by miggonza          #+#    #+#             */
/*   Updated: 2022/09/28 10:49:26 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*recive;
	size_t	i;
	size_t	length;
	size_t	j;

	if (!s)
		return (0);
	length = ft_strlen(s);
	if (length < start || *s == '\0')
		return (ft_strdup(""));
	if (len > length)
		recive = malloc(sizeof(char) * (length + 1));
	else
		recive = malloc(sizeof(char) * (len + 1));
	if (!recive)
		return (0);
	i = start;
	j = 0;
	while (i < length && j < len)
	{
		recive[j++] = s[i++];
	}
	recive[j] = '\0';
	return (recive);
}
