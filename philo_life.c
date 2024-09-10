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
	(void)info;
	int	flag;

	flag = 0;
	//printf("1\n");
	pthread_mutex_lock(&philo->data->mutex_end_eat);
	//printf("1.1\n");
	if (philo->data->n_end_eat == philo->data->n_philos)
	{
		//printf("FULL STOP\n");
		flag = 1;
	}
	//printf("1.2\n");
	pthread_mutex_unlock(&philo->data->mutex_end_eat);
	//printf("2\n");
	return (flag);
}

int	philo_full(t_philo *philo, t_info *info)
{
	//printf("PHILO FULL\n");
	pthread_mutex_lock(&philo->data->mutex_end_eat);
	if (philo->eat_count == philo->data->n_eat)
		philo->data->n_end_eat += 1;
	pthread_mutex_unlock(&philo->data->mutex_end_eat);
	if (stop_eat(philo, info) == 1)
	{
		//printf("PHILO FULL EXIT\n");
		return (1);
	}
	//printf("PHILO FULL EXIT 0\n");
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

int	philo_eat(t_philo *philo)
{
	//printf("EAT\n");
	//delayer(philo, philo->data);
	if (is_philo_dead(philo->data) == 1 || stop_eat(philo, philo->data) == 1)
			return (1);
	pthread_mutex_lock(&philo->data->mutex_fork[philo->left_fork]);
	pthread_mutex_lock(&philo->data->mutex_fork[philo->right_fork]);
	if (is_philo_dead(philo->data) == 0 && stop_eat(philo, philo->data) == 0)
	{
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
	if (is_philo_dead(philo->data) == 1 || stop_eat(philo, philo->data) == 1)
			return (1);
	return (0);
	//printf("M\n");
}

void	philo_sleep(t_philo *philo)
{
	//printf("SLEEP\n");
	print_message(SLEEP, philo, philo->data);
	ft_usleep(philo->data->t_sleep);
	if (is_philo_dead(philo->data) == 1)
			return ;
	print_message(THINK, philo, philo->data);
	philo->state = IDLE;
	//printf("END SLEEP\n");
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

void	*philo_life(void *greek)
{
	t_philo	*philo;
	t_info	*info;
	int		stop_eat;

	philo = (t_philo *)greek;
	info = philo->data;
	stop_eat = 0;
	if (check_one_death(info) == 1)
		return (NULL);
	//printf("PHILO_LIFE\n");
	while (1)
	{
		//printf("DEAD? %d\n", info->death);
		if (philo->data->n_eat >= 0)
			stop_eat = philo_full(philo, philo->data);
		//printf("FUUUUUUUCK\n");
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
		//printf("BUCLE PHILO LIFE\n");
	}
}
