/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:54:04 by miggonza          #+#    #+#             */
/*   Updated: 2022/09/20 15:54:05 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*recive;
	int		size;

	i = 0;
	size = ft_strlen(s1);
	recive = malloc(sizeof(char) * (size + 1));
	if (!recive)
		return (NULL);
	while (s1[i] != '\0')
	{
		recive[i] = s1[i];
		i++;
	}
	recive[i] = '\0';
	return (recive);
}
