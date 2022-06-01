/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medeana <medeana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:26:01 by medeana           #+#    #+#             */
/*   Updated: 2022/01/10 16:06:08 by medeana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	the_end(t_data *data)
{
	int	i;
	int	time;

	while (data->philo->dead == 0)
	{
		i = 0;
		time = get_time();
		while (i < data->count_philo)
		{
			if (data->count_philo == 1)
			{
				ft_time(data->philo->time_to_die, time);
				die(data, i);
				return (0);
			}
			else if (count_eat(data) == 1 || end2(data, i) == 1)
				return (0);
			i++;
		}
	}
	return (0);
}

int	count_eat(t_data *data)
{
	int	count;
	int	j;
	int	time;

	j = 0;
	count = 0;
	while (j < data->count_philo)
	{
		usleep(100);
		time = get_time();
		if (data->philo[j].count_eat == 0)
			count++;
		if (count == data->count_philo)
		{
			pthread_mutex_lock(&data->print);
			printf("Everyone ate!\n");
			return (1);
		}
		j++;
	}
	return (0);
}

int	end2(t_data *data, int i)
{
	int	j;
	int	time;

	j = 0;
	while (j < data->count_philo)
	{
		time = get_time();
		if (((time - data->philo[i].last_eat) > data->philo[i].time_to_die)
			&& data->philo[i].last_eat != 0)
		{
			die(data, i);
			data->philo[i].dead = 1;
			return (1);
		}
		j++;
	}
	return (0);
}

void	ft_end(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print);
}

void	clear(t_data *data)
{
	ft_end(data);
	free (data->philo);
	free(data->forks);
	free(data);
}
