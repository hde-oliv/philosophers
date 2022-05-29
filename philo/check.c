/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:06:16 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/05/28 22:06:17 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_number(char *number)
{
	int	size;
	int	i;

	size = ft_strlen(number);
	i = 1;
	if (number[0] != '-' && !ft_isdigit(number[0]))
		return (0);
	while (i < size)
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_int_extremes(char **args, int size)
{
	int			i;
	long long	j;

	i = 0;
	while (i < size)
	{
		if (ft_strlen(args[i]) > 11)
			return (1);
		j = ft_atoll(args[i]);
		if (j > 2147483647)
			return (1);
		else if (j < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

int	check_invalid_arguments(char **args, int size)
{
	int	i;
	int	f_num;

	i = 0;
	f_num = ft_atoi(args[0]);
	if (f_num < 1)
		return (1);
	while (i < size)
	{
		if (!is_number(args[i]))
			return (1);
		i++;
	}
	return (0);
}

int	arguments_are_valid(int argc, char **args)
{
	if (check_invalid_arguments(args, argc))
		return (0);
	if (check_int_extremes(args, argc))
		return (0);
	return (1);
}
