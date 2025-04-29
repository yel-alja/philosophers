/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:33:16 by yel-alja          #+#    #+#             */
/*   Updated: 2025/04/29 20:53:19 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->death_lock);
	if (philo->info->death_flag == 1)
	{
		pthread_mutex_unlock(&philo->info->death_lock);
		return (-1);
	}
	pthread_mutex_unlock(&philo->info->death_lock);
	return (0);
}

int	check_death(t_philo *philo)
{
	int	i;
	int	num;

	i = 0;
	num = philo[0].info->num_phi;
	while (i < num)
	{
		pthread_mutex_lock(philo[i].meal_mutex);
		if ((get_time() - philo[i].last_meal) >= philo[i].info->ttd)
		{
			pthread_mutex_lock(&philo[i].info->death_lock);
			philo[i].info->death_flag = 1;
			pthread_mutex_unlock(&philo[i].info->death_lock);
			pthread_mutex_lock(&philo[i].info->print_lock);
			printf("%ld\t%d\t%s\n", (get_time() - philo[i].info->start),
				philo[i].id, "died");
			pthread_mutex_unlock(&philo[i].info->print_lock);
			pthread_mutex_unlock(philo[i].meal_mutex);
			return (-1);
		}
		pthread_mutex_unlock(philo[i].meal_mutex);
		i++;
	}
	return (0);
}

void	*monitor(void *args)
{
	t_philo	*philo;
	int		num;

	philo = args;
	num = philo[0].info->num_phi;
	while (1)
	{
		pthread_mutex_lock(&philo[0].info->check_lock);
		if (((philo[0].info->philos_full == num) && (philo[0].info->ac == 6)))
		{
			philo[0].info->stop = 1;
			pthread_mutex_unlock(&philo[0].info->check_lock);
			break ;
		}
		pthread_mutex_unlock(&philo[0].info->check_lock);
		if (check_death(philo) == -1)
			break ;
		usleep(1000);
	}
	return (NULL);
}
