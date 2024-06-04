/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:54:09 by miggonza          #+#    #+#             */
/*   Updated: 2024/02/29 11:49:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strlen_gnl(char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

void	ft_bzero_gnl(void *s, size_t n)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = s;
	while (i < n)
		temp[i++] = 0;
}

char	*ft_strchr_gnl(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	if (c == '\0')
		return (str);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

void	*ft_calloc_gnl(size_t count, size_t size)
{
	void	*recive;

	recive = malloc(count * size);
	if (!recive)
		return (NULL);
	ft_bzero_gnl(recive, count * size);
	return (recive);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*recive;
	int		j;
	int		i;

	if (!s1 || !s2)
		return (0);
	recive = ft_calloc_gnl(sizeof(char),
			(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
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
	free(s1);
	return (recive);
}
