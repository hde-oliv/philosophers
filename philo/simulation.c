/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:06:33 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/05/28 22:06:34 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philo_routine(void *philo_data)
{
	t_philo	*philo;

	philo = philo_data;
	if (philo->t_philo == 1)
		return (one_philosopher(philo));
	usleep(philo->number * 300);
	while (!philo->data->simulation)
	{
		if (!take_forks(philo))
			break ;
		eat(philo);
		if (!sleep_and_think(philo))
			break ;
	}
	return (NULL);
}

int	start_simulation(int arr[5])
{
	t_philo			**philos;
	t_data			*data;
	int				i;

	if (create_data_struct(&data, arr))
		return (1);
	i = arr[0] - 1;
	while (i != -1)
	{
		(data->philos)[i] = malloc(sizeof(pthread_t));
		(data->mutexes)[i] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init((data->mutexes)[i], NULL);
		i--;
	}
	if (create_array_of_philo_data(&philos, arr, &data))
		return (1);
	i = arr[0];
	while (i-- != 0)
		pthread_create((data->philos)[i], NULL, &philo_routine, philos[i]);
	i = arr[0];
	create_watcher(data);
	while (i-- != 0)
		pthread_join(*(data->philos)[i], NULL);
	destroy_everything(data);
	return (1);
}
