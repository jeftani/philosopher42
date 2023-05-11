/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:33:35 by ajeftani          #+#    #+#             */
/*   Updated: 2023/05/11 14:33:56 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_print(char *msg, t_philo *philo)
{
	char *timeprint;
	timeprint = ft_itoa(timeoftheday() - philo->data->start_time);
	pthread_mutex_lock(&philo->data->writing);
		pthread_mutex_lock(&philo->data->max_eat_m);
		pthread_mutex_lock(&philo->data->extra);
	if (!philo->data->max_ate && !philo->data->stop_it)
		printf(" %s %s %s\n",timeprint,philo->pos_str, msg);
		pthread_mutex_unlock(&philo->data->extra);
		pthread_mutex_unlock(&philo->data->max_eat_m);
	pthread_mutex_unlock(&philo->data->writing);
	free(timeprint);
}

void philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->ffork]);
		philo_print("has taken a fork",philo);
	pthread_mutex_lock(&philo->data->forks[philo->sfork]);
		philo_print("has taken a fork",philo);
		philo_print("is eating",philo);
	pthread_mutex_lock(&philo->data->meal);
		philo->last_ate = timeoftheday();
	pthread_mutex_unlock(&philo->data->meal);
		ft_usleep(philo->data->time_to_eat);
		pthread_mutex_lock(&philo->data->eat_time_m);
		philo->ate_times++;
		pthread_mutex_unlock(&philo->data->eat_time_m);
	pthread_mutex_unlock(&philo->data->forks[philo->ffork]);
	pthread_mutex_unlock(&philo->data->forks[philo->sfork]);
}