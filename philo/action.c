/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:06:12 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/06/02 04:10:42 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int	check_for_death(size_t start_of_action, t_philo *philo)
{
	size_t	time;

	time = get_timestamp();
	if ((time - start_of_action) >= (size_t)(philo->args)[T_DIE])
	{
		*(philo->death_timestamp) = time;
		*(philo->died) = philo->number;
		return (1);
	}
	return (0);
}
static int	take_first_fork(t_philo *philo)
{
	if (philo->number == 1)
	{
		if (*(long *)(philo->mutexes)[philo->number % (philo->args)[T_PHILO]])
			return (1);
		pthread_mutex_lock((philo->mutexes)[philo->number % (philo->args)[T_PHILO]]);
	}
	else
	{
		if (*(long *)(philo->mutexes)[philo->number - 1])
			return (1);
		pthread_mutex_lock((philo->mutexes)[philo->number - 1]);
	}
	p_take_a_fork(philo);
	return (0);
}

static int	take_second_fork(t_philo *philo)
{
	if (philo->number == 1)
	{
		if (*(long *)(philo->mutexes)[philo->number - 1])
			return (1);
		pthread_mutex_lock((philo->mutexes)[philo->number - 1]);
	}
	else
	{
		if (*(long *)(philo->mutexes)[philo->number % (philo->args)[T_PHILO]])
			return (1);
		pthread_mutex_lock((philo->mutexes)[philo->number % (philo->args)[T_PHILO]]);
	}
	p_take_a_fork(philo);
	return (0);
}



int	take_a_fork(t_philo *philo, int (*f)(t_philo *philo))
{
	while (f(philo))
	{
		check_for_death(philo->last_meal, philo);
		if (*(philo->died))
			return (0);
		usleep(1000);
	}
	return (1);
}

int	do_action(t_action ac, t_philo *philo)
{
	size_t	time;

	if (ac == FIRST_FORK)
		return (take_a_fork(philo, &take_first_fork));
	else if (ac == SECOND_FORK)
		return (take_a_fork(philo, &take_second_fork));
	else if (ac == EAT)
	{
		philo->last_meal = p_eat(philo);
		philo->times_eaten += 1;
		usleep(philo->args[T_EAT] * 1000);
		pthread_mutex_unlock((philo->mutexes)[philo->number % (philo->args)[T_PHILO]]);
		pthread_mutex_unlock((philo->mutexes)[philo->number - 1]);
	}
	else if (ac == SLEEP)
	{
		time = get_timestamp();
		if ((time + philo->args[T_SLEEP]) >= (size_t)(philo->last_meal + philo->args[T_DIE]))
		{
			p_sleep(philo);
			usleep(((size_t)(philo->last_meal + philo->args[T_DIE]) - time) * 1000);
			*(philo->death_timestamp) = time;
			*(philo->died) = philo->number;
			return (0);
		}
		p_sleep(philo);
		usleep(philo->args[T_SLEEP] * 1000);
		p_think(philo);
	}
	return (1);
}
