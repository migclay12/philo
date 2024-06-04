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
//Redo headers

int ft_error(char *str)
{
	printf("%s\n", str);
	return (0);
}

int main(int argc, char **argv)
{
	t_info 	data;
	t_philo	*philo;

	ft_memset(&data, 0, sizeof(t_info));
	ft_memset(&philo, 0, sizeof(t_philo));
	if (argc != 5 && argc != 6)
		ft_error("Not enough arguments");
	if (general_info(&data, argv) == 1)
		ft_error("At least one argument is wrong");
	data.start = get_time();
	// printf("%s\n", FORKS);
	// printf("%s\n", SLEEP);
	// printf("%s\n", EAT);
	// printf("%s\n", THINK);
	// printf("%s\n", DIE);

	free(data.philo);
}