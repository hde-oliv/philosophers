/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:06:29 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/05/28 22:06:30 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_take_a_fork(t_philo *philo)
{
	printf(YELLOW "%ld " RESET BLUE "%d " RESET "has taken a fork\n", \
			(get_timestamp() - philo->start_time), philo->number);
}

size_t	p_eat(t_philo *philo)
{
	size_t	time;

	time = get_timestamp();
	printf(YELLOW "%ld " RESET BLUE "%d " RESET "is eating\n", \
			(time - philo->start_time), philo->number);
	return (time);
}

void	p_sleep(t_philo *philo)
{
	printf(YELLOW "%ld " RESET BLUE "%d " RESET "is sleeping\n", \
			(get_timestamp() - philo->start_time), philo->number);
}

void	p_think(t_philo *philo)
{
	printf(YELLOW "%ld " RESET BLUE "%d " RESET "is thinking\n", \
			(get_timestamp() - philo->start_time), philo->number);
}

void	p_die(t_philo *philo)
{
	printf(YELLOW "%ld " RESET RED "%d died\n" RESET, \
			(get_timestamp() - philo->start_time), philo->number);
}
