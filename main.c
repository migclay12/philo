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

int	ft_error(char *str)
{
	printf("%s\n", str);
	return (0);
}

void	free_philo(t_philo *philo, t_info *info)
{
	(void)philo;
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
	//printf("INFO\n");
	free(info->mutex_fork);
	//printf("PHILO\n");
	free(info->philo);
	//free(info);
	//printf("OUT\n");
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	philo;
	int		i;
	void	*philosopher;

	memset(&info, 0, sizeof(t_info));
	memset(&philo, 0, sizeof(t_philo));
	if (argc != 5 && argc != 6)
		ft_error("Not enough arguments");
	if (general_info(&info, &philo, argv) == 1)
	{
		ft_error("At least one argument is wrong");
		return (1);
	}
	info.start = get_time();
	i = 0;
	while (i < info.n_philos)
	{
		philosopher = (void *)&info.philo[i];
		if (pthread_create(&info.philo[i].thread, NULL, philo_life, philosopher) != 0)
			return (0);
		i++;
	}
	am_i_dead(info.philo, &info);
	i = 0;
	while (i < info.n_philos)
	{
		if (pthread_join(info.philo[i].thread, NULL) != 0)
			return (0);
		i++;
	}
	free_philo(&philo, &info);
}
