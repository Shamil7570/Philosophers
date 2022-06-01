/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medeana <medeana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:26:46 by medeana           #+#    #+#             */
/*   Updated: 2022/01/14 18:37:59 by medeana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count_philo)
	{
		data->philo[i].run = get_time();
		if (pthread_create(&data->philo[i].thread, NULL,
				process, &data->philo[i]) != 0)
			clear(data);
		pthread_detach(data->philo[i].thread);
		i++;
	}
	if (the_end(data) == 0)
		clear(data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	memset((void *)data, 0, sizeof(t_data));
	if (valid_arg(av) == 1)
	{
		free(data);
		return (0);
	}
	if (init(av, ac, data) == 0)
	{
		free(data);
		return (0);
	}
	create_thread(data);
	return (0);
}
