/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:23:01 by yel-alja          #+#    #+#             */
/*   Updated: 2025/07/25 18:52:35 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_event(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->info->print_lock);
	if (is_dead(philo) == -1)
	{
		pthread_mutex_unlock(&philo->info->print_lock);	
		return ;
	}
	printf("%ld\t%d\t%s\n", (get_time() - philo->info->start), philo->id, str);
	pthread_mutex_unlock(&philo->info->print_lock);
}

int	pick_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		print_event(philo, "is thinking");
		pthread_mutex_lock(philo->right_fork);
		print_event(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_event(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_event(philo, "has taken a fork");
		if (philo->info->num_phi == 1)
		{
			pthread_mutex_unlock(philo->left_fork);
			return (-1);
		}
		pthread_mutex_lock(philo->right_fork);
		print_event(philo, "has taken a fork");
	}
	return (0);
}

static int	eat_fun(t_philo *philo)
{
	if (pick_forks(philo) == -1)
		return (-1);
	print_event(philo, "is eating");
	pthread_mutex_lock(philo->meal_mutex);
	philo->last_meal = get_time();
	pthread_mutex_unlock(philo->meal_mutex);
	if (philo->info->ttd < philo->info->tte)
		usleep(philo->info->ttd * 1000);
	else
		usleep(philo->info->tte * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (is_dead(philo) == -1)
		return (-1);
	pthread_mutex_lock(&philo->info->check_lock);
	philo->times_eat++;
	if ((philo->times_eat == philo->info->noe) && philo->info->ac == 6)
		philo->info->philos_full += 1;
	pthread_mutex_unlock(&philo->info->check_lock);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if(philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
			pthread_mutex_lock(&philo->info->check_lock);
			if (philo->info->stop == 1)
			return (pthread_mutex_unlock(&philo->info->check_lock), NULL);
			pthread_mutex_unlock(&philo->info->check_lock);
			
			if (eat_fun(philo) == -1)
			break ;
			pthread_mutex_lock(&philo->info->check_lock);
			if (philo->info->stop == 1)
			return (pthread_mutex_unlock(&philo->info->check_lock), NULL);
			pthread_mutex_unlock(&philo->info->check_lock);
			print_event(philo, "is sleeping");
			if (philo->info->ttd < philo->info->tts)
			usleep(philo->info->ttd * 1000);
			else
			usleep(philo->info->tts * 1000);
			print_event(philo, "is thinking");
			usleep(philo->info->ttt * 1000);
	}
	return (NULL);
}

int	create_thread(t_philo *philo)
{
	int			i;
	int			num_philo;
	pthread_t	moni;

	i = 0;
	num_philo = philo[i].info->num_phi;
	philo[i].info->start = get_time();
	while (i < num_philo)
	{
		pthread_mutex_lock(philo[i].meal_mutex);
		philo[i].last_meal = get_time();
		pthread_mutex_unlock(philo[i].meal_mutex);
		pthread_create(&philo[i].thread, NULL, routine, (void *)&philo[i]);
		i++;
	}
	pthread_create(&moni, NULL, monitor, (void *)philo);
	i = 0;
	while (i < num_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	pthread_join(moni, NULL);
	return (0);
}
