/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:19:28 by yel-alja          #+#    #+#             */
/*   Updated: 2025/04/21 09:08:35 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

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
	int				death_flag; // should i use or remove it
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*check_lock;
	pthread_mutex_t	*death_lock;
}					t_info;

typedef struct s_philo
{
	int				id;
	int				times_eat;
	long			last_plate;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_info			*info;
}					t_philo;

int					ft_atoi(char *str, int *c);
int					init_info(t_info *info, char **av, int ac);
int					create_thread(t_philo *philo);
long				get_time(void);
int					check_number(t_info *info, char **str);
int					create_philo(t_info *info);
void				*monitor(void *args);
