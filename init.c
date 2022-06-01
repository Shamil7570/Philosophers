/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medeana <medeana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 15:48:17 by medeana           #+#    #+#             */
/*   Updated: 2022/01/14 18:36:58 by medeana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(int i, int ac, char **av, t_data *data)
{
	data->philo[i].id = i + 1;
	if (data->philo[i].id % 2 == 0)
		data->philo[i].evan = 0;
	else
		data->philo[i].evan = 1;
	init_argv(i, ac, av, data);
	data->philo[i].left_fork = &data->forks[i];
	data->philo[i].right_fork = &data->forks[(i + 1) % data->count_philo];
}

void	init_argv(int i, int ac, char **av, t_data *data)
{
	data->philo[i].time_to_die = ft_atoi(av[2]);
	data->philo[i].time_to_eat = ft_atoi(av[3]);
	data->philo[i].time_to_sleep = ft_atoi(av[4]);
	data->philo[i].last_eat = 0;
	if (ac == 6)
		data->philo[i].count_eat = ft_atoi(av[5]);
	else
		data->philo[i].count_eat = -1;
	data->philo[i].dead = 0;
	data->philo[i].count_philo = data->count_philo;
	data->philo[i].run = 0;
	data->philo[i].print = &data->print;
}

int	init(char **av, int ac, t_data *data)
{
	int	i;

	i = 0;
	if (ac < 5 || ac > 6 || ft_atoi(av[1]) > 200
		|| ft_atoi(av[1]) < 1 || ft_atoi(av[2]) < 60
		|| ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60)
		return (0);
	if (ac == 6 && ft_atoi(av[5]) < 1)
		return (0);
	data->count_philo = ft_atoi(av[1]);
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->count_philo);
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->count_philo);
	if (!(data->philo) || !(data->forks))
		return (0);
	while (i < data->count_philo)
		pthread_mutex_init(&data->forks[i++], NULL);
	pthread_mutex_init(&data->print, NULL);
	i = 0;
	while (i < data->count_philo)
		init_philo(i++, ac, av, data);
	return (1);
}
