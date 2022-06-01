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
	size_t	delay;

	philo = (t_philo *)philo_data;
	while (!philo->data->died)
	{
		delay = philo->number * 200;
		usleep(delay);
		if (!philo->data->died && !do_action(FIRST_FORK, philo))
			break ;
		if (!philo->data->died && !do_action(SECOND_FORK, philo))
			break ;
		if (!philo->data->died && !do_action(EAT, philo))
			break ;
		if (!philo->data->died && !do_action(SLEEP, philo))
			break ;
	}
	return (NULL);
}

int	start_simulation(int arr[5])
{
	t_philo			**philos;
	t_data			*data;
	int				i;

	create_data_struct(&data, arr);
	i = arr[0] - 1;
	while (i != -1)
	{
		(data->philos)[i] = malloc(sizeof(pthread_t));
		(data->mutexes)[i] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init((data->mutexes)[i], NULL);
		i--;
	}
	create_array_of_philo_data(&philos, arr, &data);
	i = arr[0];
	while (i-- != 0)
		pthread_create((data->philos)[i], NULL, &philo_routine, philos[i]);
	create_watcher(data);
	i = arr[0];
	while (i-- != 0)
		pthread_join(*(data->philos)[i], NULL);
	destroy_everything(data);
	return (1);
}
