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

static void *one_philosopher(t_philo *philo)
{
	p_take_a_fork(get_timestamp(), philo);
	usleep(philo->t_die * 1000);
	p_die(get_timestamp(), philo);
	philo->data->simulation = 1;
	return (NULL);
}

static void eat(t_philo *philo)
{
	pthread_mutex_lock((philo->mutexes)[philo->first_fork]);
	if (philo->data->simulation)
	{
		pthread_mutex_unlock((philo->mutexes)[philo->first_fork]);
		return ;
	}
	p_take_a_fork(get_timestamp(), philo);
	pthread_mutex_lock((philo->mutexes)[philo->second_fork]);
	if (philo->data->simulation)
	{
		pthread_mutex_unlock((philo->mutexes)[philo->first_fork]);
		pthread_mutex_unlock((philo->mutexes)[philo->second_fork]);
		return ;
	}
	p_take_a_fork(get_timestamp(), philo);
	philo->last_meal = get_timestamp();
	p_eat(philo->last_meal, philo);
	usleep(philo->t_eat * 1000);
	pthread_mutex_unlock((philo->mutexes)[philo->first_fork]);
	pthread_mutex_unlock((philo->mutexes)[philo->second_fork]);
	philo->times_eaten += 1;
}

static void	*philo_routine(void *philo_data)
{
	t_philo	*philo;

	philo = philo_data;
	if (philo->t_philo == 1)
		return (one_philosopher(philo));
	usleep(philo->number * 300);
	while (!philo->data->simulation)
	{
		eat(philo);
		if (philo->data->simulation)
			break ;
		p_sleep(get_timestamp(), philo);
		usleep(philo->t_sleep * 1000);
		if (philo->data->simulation)
			break ;
		p_think(get_timestamp(), philo);
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
	i = arr[0];
	create_watcher(data);
	while (i-- != 0)
		pthread_join(*(data->philos)[i], NULL);
	destroy_everything(data);
	return (1);
}
