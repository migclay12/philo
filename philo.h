/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:40:06 by miggonza          #+#    #+#             */
/*   Updated: 2024/06/04 18:40:06 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

# define FORKS	"\033[0;36m has taken a fork\033[0m"
# define THINK	"\033[0;35m is thinking\033[0m"
# define SLEEP	"\033[0;34m is sleeping\033[0m"
# define EAT	"\033[0;32m is eating\033[0m"
# define DIE	"\033[0;31m died\033[0m"

typedef enum e_philo_state
{
	IDLE = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3,
	DEAD = 4,
	FULL = 5,
}	t_state;

typedef struct s_philo
{
	int			id;
	int			eat_count;
	int			last_eat;
	int			left_fork;
	int			right_fork;
	t_state		state;
	//t_info	*info;
}	t_philo;

typedef struct s_info
{
	int		n_philos;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		n_eat;
	long	start;
	int		death;
	int		n_end_eat;
	//pthread_t		hilo; ??
	t_philo	*philo;
}	t_info;

int	general_info(t_info *data, char **argv);
int ft_error(char *str);

//Utils
long long	get_time(void);

//Functions
void	*ft_memset(void *b, int c, size_t len);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

#endif