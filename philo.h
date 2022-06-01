/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medeana <medeana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:20:18 by medeana           #+#    #+#             */
/*   Updated: 2022/01/12 15:30:31 by medeana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_philo {
	int					id;
	int					count_philo;
	int					dead;
	int					evan;
	long long			last_eat;
	long long			run;
	int					count_eat;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	pthread_t			thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*print;
}	t_philo;

typedef struct s_data {
	t_philo				*philo;
	int					count_philo;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print;
}	t_data;

int		ft_atoi(char *str);
int		valid_arg(char **av);
int		init(char **av, int ac, t_data *data);
void	init_philo(int i, int ac, char **av, t_data *data);
void	create_thread(t_data *data);
void	*process(void *arg);
int		get_time(void);
void	take_fork_r(t_philo *philo);
void	take_fork_l(t_philo *philo);
void	eating(t_philo *philo);
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);
void	die(t_data *data, int i);
int		the_end(t_data *data);
int		count_eat(t_data *data);
void	clear(t_data *data);
void	ft_end(t_data *data);
void	init_argv(int i, int ac, char **av, t_data *data);
void	ft_time(int time, int start_time);
int		end2(t_data *data, int i);

#endif
