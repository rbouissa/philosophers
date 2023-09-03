/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:09:54 by rbouissa          #+#    #+#             */
/*   Updated: 2023/06/18 15:23:04 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_fork_pair(t_info_phillo *philo)
{
	pthread_mutex_lock(&philo->fork);
	print_lock("has taken a fork\n", philo);
	pthread_mutex_lock(&philo->left->fork);
	print_lock("has taken a fork\n", philo);
	pthread_mutex_lock(&philo->for_meal);
	philo->leat_of_least = get_curent_time_in_second() - philo->time_of_first;
	pthread_mutex_unlock(&philo->for_meal);
	print_lock("is eating\n", philo);
	my_sleep(philo->ph->time_to_eat);
	pthread_mutex_unlock(&philo->left->fork);
	pthread_mutex_unlock(&philo->fork);
	print_lock("is sleeping\n", philo);
	my_sleep(philo->ph->time_to_sleep);
	print_lock("is thinking\n", philo);
}

void	*routine(void *f)
{
	t_info_phillo	*philo;
	t_info_phillo	*tmp;
	int				i;

	i = 0;
	philo = (t_info_phillo *)f;
	tmp = philo;
	if (philo->id_philo % 2 == 0)
		my_sleep(30);
	while (1)
	{
		print_fork_pair(philo);
		pthread_mutex_lock(&philo->numb_meals);
		philo->number_meals++;
		pthread_mutex_unlock(&philo->numb_meals);
	}
	return (NULL);
}

void	creat_threads(t_philo *philo, t_info_phillo *tmp,
		pthread_t *philosepher)
{
	int	i;

	i = 0;
	while (philo->numb_philo > i)
	{
		pthread_create(&philosepher[i], NULL, routine, tmp);
		pthread_detach(philosepher[i]);
		i++;
		tmp = tmp->left;
	}
}

int	check_death_and_arg(t_info_phillo *tmp, t_philo *philo, int argc)
{
	while (1)
	{
		pthread_mutex_lock(&tmp->for_meal);
		if ((get_curent_time_in_second() - tmp->time_of_first)
			- tmp->leat_of_least > philo->time_to_die)
		{
			pthread_mutex_lock(&tmp->printf);
			printf("%ld %d died\n",
				(get_curent_time_in_second() - tmp->time_of_first),
				tmp->id_philo);
			return (0);
		}
		pthread_mutex_unlock(&tmp->for_meal);
		pthread_mutex_lock(&tmp->numb_meals);
		if (argc == 6 && tmp->number_meals == philo->number_of_must_eat)
			return (0);
		pthread_mutex_lock(&tmp->numb_meals);
		tmp = tmp->left;
	}
}

int	main(int argc, char **argv)
{
	t_philo			*philo;
	t_info_phillo	*ph;
	time_t			first_time;
	pthread_t		*philosepher;
	t_info_phillo	*tmp;

	philo = malloc(sizeof(t_philo));
	philosepher = NULL;
	if (pars_philo(argv))
	{
		if (!fil_struct(philo, argv, argc))
			return (0);
		philosepher = malloc(sizeof(pthread_t) * philo->numb_philo);
		first_time = get_curent_time_in_second();
		ph = fill(philo, first_time, philo);
		tmp = ph;
		creat_threads(philo, tmp, philosepher);
		if (!check_death_and_arg(tmp, philo, argc))
			return (0);
		pthread_mutex_destroy(&tmp->fork);
	}
	else
		return (print_err());
}
