/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:06:20 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/05/28 22:06:21 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_data_struct(t_data **data, int arr[5])
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	(*data) = (t_data *)malloc(sizeof(t_data));
	(*data)->died = 0;
	(*data)->philos = (pthread_t **)malloc(sizeof(pthread_t *) * arr[0]);
	(*data)->mutexes = (pthread_mutex_t **)malloc(sizeof(pthread_mutex_t *) \
																	* arr[0]);
	(*data)->start_time = get_timestamp();
	(*data)->args = arr;
}

t_philo	*create_philo_data(int *args, int number, t_data *data)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	philo->args = args;
	philo->number = number + 1;
	philo->last_meal = data->start_time;
	philo->start_time = data->start_time;
	philo->times_eaten = 0;
	philo->data = data;
	philo->mutexes = data->mutexes;
	philo->first_fork = 0;
	philo->second_fork = 0;
	return (philo);
}

void	create_array_of_philo_data(t_philo ***p_arr, int arr[5], t_data **data)
{
	int		i;

	(*p_arr) = (t_philo **)malloc(sizeof(t_philo *) * arr[0]);
	i = arr[0] - 1;
	while (i != -1)
	{
		(*p_arr)[i] = create_philo_data(arr, i, *data);
		i--;
	}
	(*data)->t_philos = *p_arr;
}