/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:06:29 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/06/02 03:55:20 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_take_a_fork(t_philo *philo)
{
	printf("%zd %d has taken a fork\n", \
			(get_timestamp() - philo->start_time), philo->number);
}

size_t	p_eat(t_philo *philo)
{
	size_t	time;

	time = get_timestamp();
	printf("%zd %d is eating\n", \
			(time - philo->start_time), philo->number);
	return (time);
}

void	p_sleep(t_philo *philo)
{
	printf("%zd %d is sleeping\n", \
			(get_timestamp() - philo->start_time), philo->number);
}

void	p_think(t_philo *philo)
{
	printf("%zd %d is thinking\n", \
			(get_timestamp() - philo->start_time), philo->number);
}

void	p_die(t_philo *philo)
{
	printf("%zd %d died\n", \
			(*(philo->death_timestamp) - philo->start_time), philo->number);
}
