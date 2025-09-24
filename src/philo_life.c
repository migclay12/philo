/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:42:11 by miggonza          #+#    #+#             */
/*   Updated: 2024/06/11 11:42:11 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_philo *philo)
{
	if (is_philo_dead(philo->data) == 1 || stop_eat(philo) == 1)
		return (1);
	if (is_philo_dead(philo->data) == 0 && stop_eat(philo) == 0)
	{
		pthread_mutex_lock(&philo->data->mutex_fork[philo->left_fork]);
		pthread_mutex_lock(&philo->data->mutex_fork[philo->right_fork]);
		print_message(FORK, philo, philo->data);
		print_message(FORK, philo, philo->data);
		pthread_mutex_lock(&philo->mutex_time);
		philo->last_eat = get_time() - philo->data->start;
		pthread_mutex_unlock(&philo->mutex_time);
		print_message(EAT, philo, philo->data);
		philo->eat_count += 1;
		ft_usleep(philo->data->t_eat);
		philo->state = EATING;
	}
	pthread_mutex_unlock(&philo->data->mutex_fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->mutex_fork[philo->right_fork]);
	if (is_philo_dead(philo->data) == 1 || stop_eat(philo) == 1)
		return (1);
	return (0);
}

void	philo_sleep(t_philo *philo)
{
	print_message(SLEEP, philo, philo->data);
	ft_usleep(philo->data->t_sleep);
	if (is_philo_dead(philo->data) == 1)
		return ;
	print_message(THINK, philo, philo->data);
	philo->state = IDLE;
}

int	check_one_death(t_info *info)
{
	if (info->n_philos == 1)
	{
		if (info->t_die > info->t_eat + info->t_sleep)
			return (1);
	}
	return (0);
}

void	*philo_bucle(t_philo *philo, t_info *info)
{
	int		stop_eat;

	stop_eat = 0;
	while (1)
	{
		if (philo->data->n_eat >= 0)
			stop_eat = philo_full(philo);
		if (stop_eat == 1)
			return (NULL);
		if (is_philo_dead(info) == 1)
			return (NULL);
		if (philo->state == IDLE)
		{
			if (philo_eat(philo) == 1)
				return (NULL);
		}
		if (is_philo_dead(info) == 1)
			return (NULL);
		if (philo->state == EATING)
			philo_sleep(philo);
	}
}

void	*philo_life(void *greek)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)greek;
	info = philo->data;
	if (check_one_death(info) == 1)
		return (NULL);
	philo_bucle(philo, info);
	return (NULL);
}
