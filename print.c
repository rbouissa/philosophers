/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:56:55 by rbouissa          #+#    #+#             */
/*   Updated: 2023/06/17 22:57:32 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_lock(char *str, t_info_phillo *philo)
{
	pthread_mutex_lock(&philo->printf);
	printf("%ld %d %s", get_curent_time_in_second() - philo->time_of_first,
		philo->id_philo, str);
	pthread_mutex_unlock(&philo->printf);
}
