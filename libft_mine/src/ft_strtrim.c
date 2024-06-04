/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:56:02 by miggonza          #+#    #+#             */
/*   Updated: 2022/09/26 16:08:39 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	length;
	char	*recive;
	size_t	i;

	if (!s1 || !set)
		return (0);
	length = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[length - 1] && ft_strchr(set, s1[length - 1]) && length > i)
		length--;
	recive = malloc(sizeof(char) * (length - i + 1));
	if (!recive)
		return (0);
	ft_strlcpy(recive, &s1[i], length - i + 1);
	return (recive);
}
