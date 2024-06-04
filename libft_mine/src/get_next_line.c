/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:17:36 by miggonza          #+#    #+#             */
/*   Updated: 2024/02/29 11:49:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_stash(int fd, char *stash)
{
	char	*buffer;
	int		readed;

	if (!stash)
		stash = ft_calloc_gnl(sizeof(char), 1);
	buffer = ft_calloc_gnl(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	readed = 1;
	while (!ft_strchr_gnl(buffer, '\n') && readed != 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed < 0)
		{
			free (buffer);
			free (stash);
			return (0);
		}
		buffer[readed] = '\0';
		stash = ft_strjoin_gnl(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*ft_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[i])
		return (0);
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	line = ft_calloc_gnl(sizeof(char), (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n' && stash[i])
		line[i] = stash[i];
	return (line);
}

char	*ft_clean(char *stash)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (0);
	}
	temp = ft_calloc_gnl(sizeof(char), (ft_strlen_gnl(stash) - i + 1));
	if (!temp)
		return (0);
	i++;
	j = 0;
	while (stash[i])
		temp[j++] = stash[i++];
	free(stash);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	stash = ft_stash(fd, stash);
	if (!stash)
		return (0);
	line = ft_line(stash);
	stash = ft_clean(stash);
	return (line);
}
