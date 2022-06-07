/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:06:25 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/05/28 22:06:26 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philosopher(t_philo *philo)
{
	p_take_a_fork(get_timestamp(), philo);
	usleep(philo->t_die * 1000);
	p_die(get_timestamp(), philo);
	philo->data->simulation = 1;
	return (NULL);
}

int	sleep_and_think(t_philo *philo)
{
	if (philo->data->simulation)
		return (0);
	p_sleep(get_timestamp(), philo);
	usleep(philo->t_sleep * 1000);
	if (philo->data->simulation)
		return (0);
	p_think(get_timestamp(), philo);
	return (1);
}

void	eat(t_philo *philo)
{
	philo->last_meal = get_timestamp();
	p_eat(philo->last_meal, philo);
	usleep(philo->t_eat * 1000);
	pthread_mutex_unlock((philo->mutexes)[philo->first_fork]);
	pthread_mutex_unlock((philo->mutexes)[philo->second_fork]);
	philo->times_eaten += 1;
}

int	take_forks(t_philo *philo)
{
	pthread_mutex_lock((philo->mutexes)[philo->first_fork]);
	if (philo->data->simulation)
	{
		pthread_mutex_unlock((philo->mutexes)[philo->first_fork]);
		return (0);
	}
	p_take_a_fork(get_timestamp(), philo);
	pthread_mutex_lock((philo->mutexes)[philo->second_fork]);
	if (philo->data->simulation)
	{
		pthread_mutex_unlock((philo->mutexes)[philo->first_fork]);
		pthread_mutex_unlock((philo->mutexes)[philo->second_fork]);
		return (0);
	}
	p_take_a_fork(get_timestamp(), philo);
	return (1);
}
