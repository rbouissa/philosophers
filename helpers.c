/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:10:08 by rbouissa          #+#    #+#             */
/*   Updated: 2023/06/18 15:32:40 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	numb;
	int					negative;

	i = 0;
	numb = 0;
	negative = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (str[i] == '-' && ++i)
		negative = 1 - negative;
	else if (str[i] == '+' && ++i)
		negative = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		numb = numb * 10 + str[i] - 48;
		i++;
		if (numb > 2147483647 || negative)
			return (0);
	}
	if (negative)
		numb = numb * (-1);
	return (numb);
}

int	print_err(void)
{
	write(1, "invalide argument", 17);
	return (0);
}

int	is_digit1(char s)
{
	if ((s >= 48 && s <= 57))
		return (1);
	return (0);
}

int	pars_philo(char **argument)
{
	int	i;
	int	j;

	i = 1;
	while (argument[i])
	{
		j = 0;
		while (argument[i][j])
		{
			if (argument[i][j] >= '0' && argument[i][j] <= '9')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	fil_struct(t_philo *philo, char **argv, int argc)
{
	philo->numb_philo = ft_atoi(argv[1]);
	if (philo->numb_philo == 0)
		return (print_err());
	philo->time_to_die = ft_atoi(argv[2]);
	if (philo->time_to_die == 0)
		return (print_err());
	philo->time_to_eat = ft_atoi(argv[3]);
	if (philo->time_to_eat == 0)
		return (print_err());
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (philo->time_to_sleep == 0)
		return (print_err());
	if (argc == 6)
	{
		philo->number_of_must_eat = ft_atoi(argv[5]);
		if (philo->number_of_must_eat == 0)
			return (print_err());
	}
	return (1);
}
