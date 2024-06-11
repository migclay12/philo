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

//Change forks like in subject
# define FORK_L	"\033[0;36m has taken left fork\033[0m"
# define FORK_R	"\033[0;36m has taken right fork\033[0m"
# define THINK	"\033[0;35m is thinking\033[0m"
# define SLEEP	"\033[0;33m is sleeping\033[0m"
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
	int				id;
	int				eat_count;
	int				last_eat;
	int				left_fork;
	int				right_fork;
	t_state			state;
	pthread_t		thread;
	pthread_mutex_t	mutex_time;
	struct s_info	*data;
	//t_info	*info;
}	t_philo;

typedef struct s_info
{
	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	long			start;
	int				death;
	int				n_end_eat;
	pthread_mutex_t	*mutex_fork;
	t_philo			*philo;
}	t_info;

//int	general_info(t_info *data, char **argv);
int	general_info(t_info *info, t_philo *philo, char **argv);
int ft_error(char *str);
void *philo_life(void *data);

//Utils
void ft_usleep(int ms);
long long	get_time(void);
void		print_message(char *str, t_philo *philo, t_info *info);
void	delayer(t_philo *philo, t_info *info);

//Functions
void	*ft_memset(void *b, int c, size_t len);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);


#endif