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
//gets the seconds and then adds the miliseconds (usec)
long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void ft_usleep(int ms)
{
    long long start_time;
    long long end_time;

	start_time = get_time();
	end_time = start_time + ms;
    while (get_time() < end_time) {
        usleep(1000); // Sleep for 1 millisecond (1000 microseconds)
    }
}
