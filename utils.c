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

long time_dif(t_info *info)
{
	long	present;


	present = get_time();
	//return (present - 0);
	//printf("STAAAAAAAAAAAART: %ld\n", info->start);
	return (present - info->start);
}

void	print_message(char *str, t_philo *philo, t_info *info)
{
	//printf("BEFORE MESSAGE\n");
	printf("%ldms  %d %s\n", time_dif(info), philo->id, str);
	//printf("AFTER MESSAGE\n");
}

void	delayer(t_philo *philo, t_info *info)
{
	int	time_left;

	time_left = 0;
	time_left = info->t_die
		- (time_dif(info) - philo->last_eat);
	time_left /= 2;
	if (time_left > info->t_die || time_left > 1000)
		return ;
	usleep(time_left);
}

//gets the seconds and then adds the miliseconds (usec)
long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

// Sleep for 1 millisecond (1000 microseconds)
void	ft_usleep(int ms)
{
	long long	start_time;
	long long	end_time;

	start_time = get_time();
	end_time = start_time + ms;
	while (get_time() < end_time)
	{
		usleep(1000);
	}
}
