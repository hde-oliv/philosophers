/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:06:20 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/06/02 03:55:37 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*(unsigned char *)s++ = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	if (count * size == 0)
		return (p);
	ft_bzero(p, count * size);
	return (p);
}

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
	(*data)->trylock = ft_calloc(sizeof(int), arr[0]);
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
	philo->death_timestamp = &(data->death_timestamp);
	philo->died = &(data->died);
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
