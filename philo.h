/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:01:15 by rbouissa          #+#    #+#             */
/*   Updated: 2023/06/17 23:08:56 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_info_phillo
{
	int						id_philo;
	time_t					time_of_first;
	int						number_meals;
	pthread_mutex_t			for_meal;
	time_t					leat_of_least;
	pthread_mutex_t			fork;
	pthread_mutex_t			numb_meals;
	pthread_mutex_t			printf;
	struct s_info_phillo	*right;
	struct s_info_phillo	*left;
	struct s_philo			*ph;
}							t_info_phillo;
typedef struct s_philo
{
	int						numb_philo;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						number_of_must_eat;
	t_info_phillo			*single_philo;
}							t_philo;
int							ft_atoi(const char *str);
int							print_err(void);
time_t						get_curent_time_in_second(void);
time_t						time_delai(struct timeval delai,
								struct timeval start);
void						my_sleep(time_t time);
int							pars_philo(char **argument);
int							is_digit1(char s);
t_info_phillo				*fill(t_philo *data, time_t first_time,
								t_philo *tm);
void						fill_lite(t_info_phillo *data, int i, time_t time,
								t_philo *tmp);
int							fil_struct(t_philo *philo, char **argv, int argc);
void						print_lock(char *str, t_info_phillo *philo);
#endif
