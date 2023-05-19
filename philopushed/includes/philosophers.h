/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 01:23:16 by ajeftani          #+#    #+#             */
/*   Updated: 2023/05/18 01:42:39 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int					ate_times;
	int					pos;
	char				*pos_str;
	int					ffork;
	int					sfork;
	unsigned long		last_ate;
	pthread_t			thread_id;
	t_data				*data;
}						t_philo;

typedef struct s_data
{
	int					count;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					eat_count_max;
	unsigned long		start_time;
	int					max_ate;
	int					stop_it;
	t_philo				*philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		meal;
	pthread_mutex_t		writing;
	pthread_mutex_t		extra;
	pthread_mutex_t		max_eat_m;
	pthread_mutex_t		eat_time_m;
}						t_data;

void					ft_usleep(long time);
int						ft_atoi(const char *str);
int						ft_init(t_data *data, char **argv, int argc);
char					*ft_itoa(int n);
int						ft_create_thread(t_data *data);
void					philo_eat(t_philo *philo);
void					philo_print(char *msg, t_philo *philo);
long					timeoftheday(void);
void					todie(t_data *data);
void					threads_end(t_data *data);
void					ft_free_destroy(t_data *data);
void					ft_limit_meals(t_data *data);

#endif