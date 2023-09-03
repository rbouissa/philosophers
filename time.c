/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:10:27 by rbouissa          #+#    #+#             */
/*   Updated: 2023/06/17 22:57:27 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_curent_time_in_second(void)
{
	struct timeval	current_time;
	time_t			curent_time_in_second;

	gettimeofday(&current_time, NULL);
	curent_time_in_second = (current_time.tv_sec * 1000) + (current_time.tv_usec
			/ 1000);
	return (curent_time_in_second);
}

time_t	time_delai(struct timeval delai, struct timeval start)
{
	time_t	d;
	time_t	s;
	time_t	res;

	s = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	d = (delai.tv_sec * 1000) + (delai.tv_usec / 1000);
	res = d - s;
	return (res);
}

void	my_sleep(time_t time)
{
	struct timeval	start;
	struct timeval	delai;

	gettimeofday(&start, NULL);
	gettimeofday(&delai, NULL);
	while (1)
	{
		gettimeofday(&delai, NULL);
		if (time_delai(delai, start) >= time)
			break ;
		usleep(150);
	}
}

void	fill_lite(t_info_phillo *data, int i, time_t time, t_philo *tmp)
{
	data->time_of_first = time;
	data->id_philo = i + 1;
	data->number_meals = 0;
	data->ph = tmp;
	data->leat_of_least = 0;
	pthread_mutex_init(&data->fork, NULL);
	pthread_mutex_init(&data->printf, NULL);
	pthread_mutex_init(&data->for_meal, NULL);
}

t_info_phillo	*fill(t_philo *data, time_t first_time, t_philo *tm)
{
	t_info_phillo	*tmp;
	t_info_phillo	*tmp2;
	int				i;

	i = 0;
	tmp = malloc(sizeof(t_info_phillo));
	tmp2 = tmp;
	while (i < data->numb_philo)
	{
		fill_lite(tmp, i, first_time, tm);
		if (i < data->numb_philo - 1)
		{
			tmp->right = malloc(sizeof(t_info_phillo));
			tmp->right->left = tmp;
			tmp = tmp->right;
		}
		if (i == data->numb_philo - 1)
		{
			tmp->right = malloc(sizeof(t_info_phillo));
			tmp->right = tmp2;
			tmp2->left = tmp;
		}
		i++;
	}
	return (tmp2);
}
