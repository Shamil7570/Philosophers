/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medeana <medeana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 16:05:15 by medeana           #+#    #+#             */
/*   Updated: 2022/01/12 15:31:09 by medeana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork_l(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->print);
	printf("%lldms %5d has taken a left fork\n", get_time()
		- philo->run, philo->id);
	pthread_mutex_unlock(philo->print);
}

void	take_fork_r(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->print);
	printf("%lldms %5d has taken a right fork\n", get_time()
		- philo->run, philo->id);
	pthread_mutex_unlock(philo->print);
}

void	eating(t_philo *philo)
{
	int	start_time;

	take_fork_l(philo);
	take_fork_r(philo);
	start_time = get_time();
	pthread_mutex_lock(philo->print);
	printf("%lldms %5d has eating\n", get_time()
		- philo->run, philo->id);
	pthread_mutex_unlock(philo->print);
	philo->last_eat = get_time();
	ft_time(philo->time_to_eat, start_time);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (philo->count_eat > 0)
		philo->count_eat--;
}

void	die(t_data *data, int i)
{
	pthread_mutex_lock(&data->print);
	printf ("%lldms %5d has dead\n", get_time()
		- data->philo[i].run, data->philo[i].id);
}
