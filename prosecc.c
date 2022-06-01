/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prosecc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medeana <medeana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 15:46:21 by medeana           #+#    #+#             */
/*   Updated: 2022/01/10 14:46:40 by medeana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*process(void *argv)
{
	t_philo	*philo;

	philo = (t_philo *)argv;
	if (philo->evan == 0)
		usleep(100);
	if (philo->count_philo > 1)
	{
		while (philo->dead == 0)
		{
			eating(philo);
			sleeping(philo);
			thinking(philo);
		}
	}
	return (NULL);
}
