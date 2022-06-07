/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:06:25 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/05/28 22:06:26 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <bits/pthreadtypes.h>
# include <unistd.h>

enum e_philo
{
	T_PHILO = 0,
	T_DIE,
	T_EAT,
	T_SLEEP,
	T_LOOP,
};

typedef struct s_data
{
	int				simulation;
	size_t			start_time;
	int				*args;
	pthread_t		**philos;
	pthread_mutex_t	**mutexes;
	void			*t_philos;
}	t_data;

typedef struct s_philo
{
	int				number;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				t_loop;
	int				t_philo;
	int				first_fork;
	int				second_fork;
	size_t			last_meal;
	size_t			start_time;
	int				times_eaten;
	t_data			*data;
	pthread_mutex_t	**mutexes;
}	t_philo;

// Prints
void		p_take_a_fork(size_t time, t_philo *philo);
void		p_eat(size_t time, t_philo *philo);
void		p_sleep(size_t time, t_philo *philo);
void		p_think(size_t time, t_philo *philo);
void		p_die(size_t time, t_philo *philo);

// Check
int			check_int_extremes(char **args, int size);
int			check_invalid_arguments(char **args, int size);
int			arguments_are_valid(int argc, char **args);

// Utils
int			ft_isdigit(int c);
int			ft_isspace(char c);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
long long	ft_atoll(const char *str);

// Time
size_t		get_timestamp(void);

// Simulation
int			start_simulation(int arr[5]);

// Constructors
void		create_data_struct(t_data **data, int arr[5]);
t_philo		*create_philo_data(int *args, int number, t_data *data);
void		create_array_of_philo_data(t_philo ***p_arr, \
									int arr[5], t_data **data);

// Watcher
void		create_watcher(t_data *data);
void		destroy_everything(t_data *data);

// Actions
void		*one_philosopher(t_philo *philo);
int			sleep_and_think(t_philo *philo);
void		eat(t_philo *philo);
int			take_forks(t_philo *philo);

#endif
