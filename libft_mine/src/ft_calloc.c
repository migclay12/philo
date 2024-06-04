/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:17:01 by miggonza          #+#    #+#             */
/*   Updated: 2022/09/20 13:17:03 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*recive;

	if (size == SIZE_MAX || count == SIZE_MAX)
		return (NULL);
	recive = malloc(count * size);
	if (!recive)
		return (NULL);
	ft_bzero(recive, count * size);
	return (recive);
}
