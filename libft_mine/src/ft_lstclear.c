/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:31:52 by miggonza          #+#    #+#             */
/*   Updated: 2022/09/28 11:38:33 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*new;
	t_list	*aux;

	if (!lst || !del)
		return ;
	aux = *lst;
	while (aux)
	{
		new = aux->next;
		del(aux->content);
		free(aux);
		aux = new;
	}
	*lst = NULL;
}
