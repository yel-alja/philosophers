/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:19:28 by yel-alja          #+#    #+#             */
/*   Updated: 2025/05/19 11:30:45 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_info
{
	int				num_phi;
	int				ac;
	int				ttd;
	int				tte;
	int				tts;
	int				noe;
	long			start;
	int				philos_full;
	int				stop;
	int				death_flag;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	check_lock;
	pthread_mutex_t	death_lock;
}					t_info;

typedef struct s_philo
{
	int				id;
	int				times_eat;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*meal_mutex;
	t_info			*info;
}					t_philo;

int					create_philo(t_info *info);
int					ft_atoi(char *str, int *c);
int					init_info(t_info *info, char **av, int ac);
int					create_thread(t_philo *philo);
long				get_time(void);
void				*monitor(void *args);
void				print_event(t_philo *philo, char *str);
void				initialize_mutexes(pthread_mutex_t *forks, t_info *info,
						pthread_mutex_t *meal_mutex);
int					is_dead(t_philo *philo);

#endif