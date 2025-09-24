/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:43:57 by miggonza          #+#    #+#             */
/*   Updated: 2024/09/18 19:29:25 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	stop_eat(t_philo *philo)
{
	int	flag;

	flag = 0;
	pthread_mutex_lock(&philo->data->mutex_end_eat);
	if (philo->data->n_end_eat == philo->data->n_philos)
		flag = 1;
	pthread_mutex_unlock(&philo->data->mutex_end_eat);
	return (flag);
}

int	philo_full(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex_end_eat);
	if (philo->eat_count == philo->data->n_eat)
		philo->data->n_end_eat += 1;
	pthread_mutex_unlock(&philo->data->mutex_end_eat);
	if (stop_eat(philo) == 1)
		return (1);
	return (0);
}

int	is_philo_dead(t_info *info)
{
	int	flag;

	flag = 0;
	pthread_mutex_lock(&info->mutex_dead);
	if (info->death == 1)
		flag = 1;
	pthread_mutex_unlock(&info->mutex_dead);
	return (flag);
}

void	am_i_dead(t_philo *philo, t_info *info)
{
	int	n;

	n = 0;
	while (1)
	{
		if (n == info->n_philos)
			n = 0;
		if (stop_eat(&philo[n]) == 1)
			return ;
		pthread_mutex_lock(&info->philo[n].mutex_time);
		if ((time_dif(info) - info->philo[n].last_eat) >= info->t_die)
		{
			pthread_mutex_unlock(&info->philo[n].mutex_time);
			pthread_mutex_lock(&info->mutex_dead);
			info->death = 1;
			pthread_mutex_unlock(&info->mutex_dead);
			printf("%ldms  %d %s\n", time_dif(info), n + 1, DIE);
			return ;
		}
		pthread_mutex_unlock(&info->philo[n].mutex_time);
		n++;
		usleep(50);
	}
}
