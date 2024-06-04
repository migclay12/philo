/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:29:25 by miggonza          #+#    #+#             */
/*   Updated: 2022/09/23 12:29:25 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	char	*recive;
	int		j;
	int		i;

	if (!s1 || !s2)
		return (0);
	recive = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!recive)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		recive[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		recive[i] = s2[j];
		i++;
		j++;
	}
	recive[i] = '\0';
	return (recive);
}
