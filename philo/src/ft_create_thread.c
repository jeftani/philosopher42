/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:23:41 by ajeftani          #+#    #+#             */
/*   Updated: 2023/05/11 13:11:53 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void ft_usleep(long time)
{
	long start;

	start = timeoftheday();
	while (timeoftheday() - start <= time)
		usleep(50);
}

void *routine(void* param)
{
    t_philo *philo;
    philo = (t_philo*)param;
    while (1)
    {
		pthread_mutex_lock(&philo->data->max_eat_m);
		if (!(!philo->data->max_ate && !philo->data->stop_it))
			break;
		pthread_mutex_unlock(&philo->data->max_eat_m);
        philo_eat(philo);
        philo_print("is sleeping", philo);
        ft_usleep(philo->data->time_to_sleep);
        philo_print("is thinking", philo);
    }
    return NULL;
}

int ft_create_thread(t_data *data)
{
	data->start_time = timeoftheday();
	int i;
	i = -1;
	while(++i < data->count)
	{
		data->philos[i].data = data;
		data->philos[i].last_ate = timeoftheday();
		int b = pthread_create(&(data->philos[i].thread_id),NULL,routine,&data->philos[i]);
		if(b)
			return(1);
		usleep(100);
	}
	todie(data);
	i = 0;
	while(i < data->count)
	{
	 	pthread_detach(data->philos[i++].thread_id);
	}
	//ft_free_destroy(data);
	//system("leaks philo");
	return(1);
}