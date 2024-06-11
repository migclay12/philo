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

int	philo_full(t_philo *philo)
{
	if (philo->eat_count == philo->data->n_eat)
		philo->data->n_end_eat += 1;
	if (philo->data->n_end_eat == philo->data->n_philos)
		return (1);
	else
		return (0);
}

/* int	philo_dead(t_philo *philo)
{

} */

void philo_eat(t_philo *philo)
{
	//printf("EAT\n");
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
	//printf("E\n");
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
	//printf("M\n");
}

void	philo_sleep(t_philo *philo)
{
	//printf("SLEEP\n");
	print_message(SLEEP, philo, philo->data);
	ft_usleep(philo->data->t_sleep);
	print_message(THINK, philo, philo->data);
	philo->state = IDLE;
}

void *philo_life(void *greek)
{
	t_philo	*philo;
	int		stop_eat;

	philo = (t_philo *)greek;
	//printf("PHILO_LIFE\n");
	while(1)
	{
		if (philo->data->n_eat >= 0)
			stop_eat = philo_full(philo);
		if (stop_eat == 1)
			return (NULL);
		philo_eat(philo);
		philo_sleep(philo);
	}
	//return (NULL);
}