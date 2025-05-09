/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:31:09 by yel-alja          #+#    #+#             */
/*   Updated: 2025/04/24 21:01:48 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str, int *c)
{
	int		i;
	long	r;
	int		s;

	i = 0;
	r = 0;
	s = 1;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == 43) || (str[i] == 45))
	{
		if (str[i] == 45)
			s *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		r = r * 10 + (str[i] - 48);
		if ((r * s) > INT_MAX || (r * s) < INT_MIN)
			*c = -1;
		i++;
	}
	return ((int)r * s);
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	initialize_mutexes(pthread_mutex_t *forks, t_info *info,
		pthread_mutex_t *meal_mutex)
{
	int	j;

	j = 0;
	while (j < info->num_phi)
	{
		pthread_mutex_init(&forks[j], NULL);
		pthread_mutex_init(&meal_mutex[j], NULL);
		j++;
	}
	pthread_mutex_init(&info->print_lock, NULL);
	pthread_mutex_init(&info->check_lock, NULL);
	pthread_mutex_init(&info->death_lock, NULL);
}
