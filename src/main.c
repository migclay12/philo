/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:40:12 by miggonza          #+#    #+#             */
/*   Updated: 2024/06/04 18:40:12 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_philos)
	{
		pthread_mutex_destroy(&info->philo[i].mutex_time);
		pthread_mutex_destroy(&info->mutex_fork[i]);
		i++;
	}
	pthread_mutex_destroy(&info->mutex_dead);
	pthread_mutex_destroy(&info->mutex_end_eat);
	pthread_mutex_destroy(&info->mutex_write);
	free(info->mutex_fork);
	free(info->philo);
}

int	get_info(t_info *info, t_philo *philo, int argc, char **argv)
{
	memset(info, 0, sizeof(t_info));
	memset(philo, 0, sizeof(t_philo));
	if (argc != 5 && argc != 6)
	{
		printf("Not enough arguments\n");
		return (1);
	}
	if (general_info(info, argv) == 1)
	{
		printf("At least one argument is wrong\n");
		return (1);
	}
	return (0);
}

int	create_threads(t_info info)
{
	int		i;
	void	*p;

	i = -1;
	while (i++ < info.n_philos - 1)
	{
		p = (void *)&info.philo[i];
		if (i % 2 == 0)
		{
			if (pthread_create(&info.philo[i].thread, NULL, philo_life, p) != 0)
				return (1);
		}
	}
	usleep(1);
	i = -1;
	while (i++ < info.n_philos - 1)
	{
		p = (void *)&info.philo[i];
		if (i % 2 != 0)
		{
			if (pthread_create(&info.philo[i].thread, NULL, philo_life, p) != 0)
				return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	philo;
	int		i;

	if (get_info(&info, &philo, argc, argv) == 1)
		return (0);
	info.start = get_time();
	if (create_threads(info) == 1)
		return (0);
	am_i_dead(info.philo, &info);
	i = 0;
	while (i < info.n_philos)
	{
		if (pthread_join(info.philo[i].thread, NULL) != 0)
			return (0);
		i++;
	}
	free_philo(&info);
}
