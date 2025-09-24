/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:40:31 by miggonza          #+#    #+#             */
/*   Updated: 2024/06/04 18:40:31 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_input(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				printf("%s argument is invlaid\n", argv[i]);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	philo_info(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_philos)
	{
		info->philo[i].data = info;
		info->philo[i].id = i + 1;
		info->philo[i].eat_count = 0;
		info->philo[i].last_eat = 0;
		info->philo[i].left_fork = i;
		info->philo[i].right_fork = (i + 1) % info->n_philos;
		info->philo[i].state = IDLE;
		if (pthread_mutex_init(&info->mutex_fork[i], NULL))
			return (1);
		if (pthread_mutex_init(&info->philo[i].mutex_time, NULL))
			return (1);
		if (pthread_mutex_init(&info->mutex_dead, NULL))
			return (1);
		if (pthread_mutex_init(&info->mutex_end_eat, NULL))
			return (1);
		if (pthread_mutex_init(&info->mutex_write, NULL))
			return (1);
		i++;
	}
	return (0);
}

int	save_info(t_info *info, char **argv)
{
	info->n_philos = ft_atoi(argv[1]);
	info->t_die = ft_atoi(argv[2]);
	info->t_eat = ft_atoi(argv[3]);
	info->t_sleep = ft_atoi(argv[4]);
	info->death = 0;
	info->n_end_eat = 0;
	if (info->n_philos < 1 || info->n_philos > 200 || info->t_die < 60
		|| info->t_eat < 60 || info->t_sleep < 60)
		return (1);
	if (argv[5])
	{
		info->n_eat = ft_atoi(argv[5]);
		if (info->n_eat <= 0)
			return (1);
	}
	else
		info->n_eat = -1;
	return (0);
}

int	general_info(t_info *info, char **argv)
{
	if (check_input(argv) == 1)
		return (1);
	if (save_info(info, argv) == 1)
		return (1);
	info->philo = malloc(sizeof(t_philo) * info->n_philos);
	if (info->philo == NULL)
		return (1);
	info->mutex_fork = (pthread_mutex_t *)malloc(info->n_philos
			* sizeof(pthread_mutex_t));
	if (info->mutex_fork == NULL)
		return (1);
	if (philo_info(info) == 1)
		return (1);
	return (0);
}
