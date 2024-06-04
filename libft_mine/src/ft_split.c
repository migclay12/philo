/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:17:46 by miggonza          #+#    #+#             */
/*   Updated: 2022/09/29 18:45:03 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	count_string(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static int	count_word(const char *s, char c, int i)
{
	int	cont;

	cont = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		cont++;
	}
	return (cont);
}

static char	**freemem(char **exit, int i)
{
	while (i >= 0)
	{
		free(exit[i]);
		i--;
	}
	free(exit);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		countstr;
	int		countwrd;
	char	**idk;
	size_t	count;

	if (!s)
		return (NULL);
	countstr = count_string(s, c);
	idk = malloc(sizeof(char *) * (countstr + 1));
	if (!idk)
		return (NULL);
	idk[countstr] = NULL;
	countwrd = 0;
	count = 0;
	while (countwrd < countstr)
	{
		while (s[count] == c)
			count++;
		idk[countwrd] = ft_substr(s, count, count_word(s, c, count));
		if (!idk[countwrd])
			freemem(idk, countwrd);
		count += count_word(s, c, count);
		countwrd++;
	}
	return (idk);
}
