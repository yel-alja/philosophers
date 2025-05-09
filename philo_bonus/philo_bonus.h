/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:46:32 by yel-alja          #+#    #+#             */
/*   Updated: 2025/05/06 09:57:58 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

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
}					t_info;

typedef struct s_philo
{
	int				id;
	int				times_eat;
	long			last_meal;
	pthread_t		thread;
	t_info			*info;
}					t_philo;


int	init_info(t_info *info, char **av, int ac);
int	ft_atoi(char *str, int *c);
long	get_time(void);
#endif