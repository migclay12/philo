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

int	stop_eat(t_philo *philo, t_info *info)
{
	(void)philo;
	int	flag;

	flag = 0;
	printf("1\n");
	pthread_mutex_lock(&info->mutex_end_eat);
	printf("1.1\n");
	if (info->n_end_eat == info->n_philos)
		flag = 1;
	printf("1.2\n");
	pthread_mutex_unlock(&info->mutex_end_eat);
	printf("2\n");
	return (flag);
}

int	philo_full(t_philo *philo, t_info *info)
{
	printf("PHILO FULL\n");
	pthread_mutex_lock(&philo->data->mutex_end_eat);
	if (philo->eat_count == philo->data->n_eat)
		philo->data->n_end_eat += 1;
	pthread_mutex_unlock(&philo->data->mutex_end_eat);
	if (stop_eat(philo, info) == 1)
	{
		printf("PHILO FULL EXIT\n");
		return (1);
	}
	printf("PHILO FULL EXIT 0\n");
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

void	philo_eat(t_philo *philo)
{
	printf("EAT\n");
	//delayer(philo, philo->data);
	pthread_mutex_lock(&philo->data->mutex_fork[philo->left_fork]);
	//printf("A\n");
	print_message(FORK_L, philo, philo->data);
	//printf("B\n");
	//check death?
	pthread_mutex_lock(&philo->data->mutex_fork[philo->right_fork]);
	//printf("C\n");
	print_message(FORK_R, philo, philo->data);
	//printf("D\n");
	//check dead again?
	//if not dead
	pthread_mutex_lock(&philo->mutex_time);
	//printf("E %ld\n", philo->data->start);
	philo->last_eat = get_time() - philo->data->start;
	//printf("F\n");
	pthread_mutex_unlock(&philo->mutex_time);
	//printf("G\n");
	print_message(EAT, philo, philo->data);
	//printf("H\n");
	philo->eat_count += 1;
	//printf("I\n");
	ft_usleep(philo->data->t_eat);
	//printf("J\n");
	philo->state = EATING;
	//printf("K\n");
	pthread_mutex_unlock(&philo->data->mutex_fork[philo->left_fork]);
	//printf("L\n");
	pthread_mutex_unlock(&philo->data->mutex_fork[philo->right_fork]);
	printf("M\n");
}

void	philo_sleep(t_philo *philo)
{
	printf("SLEEP\n");
	print_message(SLEEP, philo, philo->data);
	ft_usleep(philo->data->t_sleep);
	print_message(THINK, philo, philo->data);
	philo->state = IDLE;
	printf("END SLEEP\n");
}

void	*philo_life(void *greek)
{
	t_philo	*philo;
	t_info	*info;
	int		stop_eat;

	philo = (t_philo *)greek;
	info = philo->data;
	stop_eat = 0;
	printf("PHILO_LIFE\n");
	while (1)
	{
		printf("DEAD? %d\n", info->death);
		if (philo->data->n_eat >= 0)
			stop_eat = philo_full(philo, philo->data);
		printf("FUUUUUUUCK\n");
		if (stop_eat == 1)
			return (NULL);
		if (is_philo_dead(info) == 1)
			return (NULL);
		philo_eat(philo);
		if (is_philo_dead(info) == 1)
			return (NULL);
		philo_sleep(philo);
		printf("BUCLE PHILO LIFE\n");
	}
	//return (NULL);
}
