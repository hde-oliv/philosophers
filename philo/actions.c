#include "philo.h"

void	take_a_fork(int philo, struct timeval *time)
{
	gettimeofday(time, NULL);
	printf(YELLOW "%ld " RESET BLUE "%d " RESET "has taken a fork\n" , time->tv_usec, philo);
}

void	eat(int philo, struct timeval *time)
{
	gettimeofday(time, NULL);
	printf(YELLOW "%ld " RESET BLUE "%d " RESET "is eating\n" , time->tv_usec, philo);
}

void	m_sleep(int philo, struct timeval *time)
{
	gettimeofday(time, NULL);
	printf(YELLOW "%ld " RESET BLUE "%d " RESET "is sleeping\n" , time->tv_usec, philo);
}

void	think(int philo, struct timeval *time)
{
	gettimeofday(time, NULL);
	printf(YELLOW "%ld " RESET BLUE "%d " RESET "is thinking\n" , time->tv_usec, philo);
}

void	die(int philo, struct timeval *time)
{
	gettimeofday(time, NULL);
	printf(YELLOW "%ld " RESET RED "%d died\n"  RESET, time->tv_usec, philo);
}
