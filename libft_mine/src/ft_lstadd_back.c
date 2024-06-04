/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:31:48 by miggonza          #+#    #+#             */
/*   Updated: 2022/09/28 08:27:04 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*recive;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	recive = ft_lstlast(*lst);
	recive->next = new;
}
