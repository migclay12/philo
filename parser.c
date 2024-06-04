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

int check_input(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				printf("%s\n", argv[i]);
				ft_error("Argument is invlaid");
				return (1);
			}
				
			j++;
		}
		i++;
	}
	return (0);
}

void	philo_info(t_info *data)
{
	int i;

	i = 0;
	while (i < data->n_philos)
	{
		data->philo[i].id = i + 1;
		data->philo[i].eat_count = 0;
		data->philo[i].last_eat = 0;
		data->philo[i].left_fork = i;
		data->philo[i].right_fork = (i + 1) % data->n_philos;
		data->philo[i].state = IDLE;
		i++;
	}
}

int	general_info(t_info *data, char **argv)
{
	if (check_input(argv) == 1)
		return (1);
	data->n_philos = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->death = 0;
	data->n_end_eat = 0;
	//Check if all this is accurate
	if (data->n_philos < 1 || data->n_philos > 200 || data->t_die < 60
		|| data->t_eat < 60 || data->t_sleep < 60)
		return (1);
	if (argv[5])
	{
		data->n_eat = ft_atoi(argv[5]);
		if (data->n_eat <= 0)
			return (1);
	}
	else
		data->n_eat = -1;
	data->philo = malloc(sizeof(t_philo) * data->n_philos);
	if (data->philo == NULL)
		return (1);
	philo_info(data);
	// printf("%d\n", data->n_philos);
	// printf("%d\n", data->t_die);
	// printf("%d\n", data->t_eat);
	// printf("%d\n", data->t_sleep);
	// printf("%d\n", data->n_eat);
	return (0);
	
}
