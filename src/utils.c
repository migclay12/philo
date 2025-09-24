/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:39:59 by miggonza          #+#    #+#             */
/*   Updated: 2024/06/04 18:39:59 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	time_dif(t_info *info)
{
	long	present;

	present = get_time();
	return (present - info->start);
}

void	print_message(char *str, t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&info->mutex_write);
	pthread_mutex_lock(&info->mutex_dead);
	if (info->death == 0)
		printf("%ldms  %d %s\n", time_dif(info), philo->id, str);
	pthread_mutex_unlock(&info->mutex_dead);
	pthread_mutex_unlock(&info->mutex_write);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(int ms)
{
	long long	start_time;
	long long	end_time;

	start_time = get_time();
	end_time = start_time + ms;
	while (get_time() < end_time)
		usleep(50);
}
