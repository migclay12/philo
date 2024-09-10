/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:43:57 by miggonza          #+#    #+#             */
/*   Updated: 2024/09/10 18:52:15 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	am_i_dead(t_philo *philo, t_info *info)
{
	//printf("DEAD\n");
	//printf("ID %d\n", philo->id);
	int n;

	n = 0;
	while (1)
	{
		//printf("BUCLE DEAD %d\n", n);
		if (n == info->n_philos)
			n = 0;
		if (stop_eat(&philo[n], info) == 1)
		{
			//printf("FULL DEAD STOP\n");
			return ;
		}
		//printf("EAT ERROR 2\n");
		pthread_mutex_lock(&info->philo[n].mutex_time);
		//printf("EAT ERROR 3\n");
		//if (philo[n].last_eat >= info->t_die)
		//int time = time_dif(info);
		if ((time_dif(info) - info->philo[n].last_eat) >= info->t_die)
		{
			pthread_mutex_unlock(&info->philo[n].mutex_time);
			pthread_mutex_lock(&info->mutex_dead);
			info->death = 1;
			pthread_mutex_unlock(&info->mutex_dead);
			//printf("EAT NOT\n");
			printf("%ldms  %d %s\n", time_dif(info), philo->id, DIE);
			//print_message(DIE, philo, info);
			//printf("RETURN?\n");
			return ;
		}
		//printf("EAT YES\n");
		pthread_mutex_unlock(&info->philo[n].mutex_time);
		n++;
		usleep(1000);
	}
}