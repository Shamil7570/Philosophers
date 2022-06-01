/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medeana <medeana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:50:45 by medeana           #+#    #+#             */
/*   Updated: 2022/01/14 18:46:01 by medeana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	printf("%lldms %5d has thinking\n", get_time() - philo->run, philo->id);
	pthread_mutex_unlock(philo->print);
}

void	sleeping(t_philo *philo)
{
	int	start_sleep;

	start_sleep = get_time();
	pthread_mutex_lock(philo->print);
	printf("%lldms %5d has sleeping\n", get_time() - philo->run, philo->id);
	pthread_mutex_unlock(philo->print);
	ft_time(philo->time_to_sleep, start_sleep);
}
