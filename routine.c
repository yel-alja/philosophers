/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:23:01 by yel-alja          #+#    #+#             */
/*   Updated: 2025/04/21 09:08:56 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void print_event(t_philo *philo ,pthread_mutex_t *mutex , char *str)
{
	pthread_mutex_lock(mutex);
	printf("%ld\t%d\t%s\n" , (get_time() - philo->info->start) , philo->id, str);
	pthread_mutex_unlock(mutex);
}

static void eat_fun(t_philo *philo)
{
	if(philo->id % 2 != 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_event(philo , philo->info->print_lock , "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_event(philo , philo->info->print_lock , "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_event(philo , philo->info->print_lock , "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_event(philo , philo->info->print_lock , "has taken a fork");
	}
	print_event(philo , philo->info->print_lock , "is eating");
	usleep(philo->info->tte * 1000);
	philo->last_plate = get_time();//?	
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_lock(philo->info->check_lock);
	if(((philo->times_eat += 1) == philo->info->noe) && philo->info->ac == 6)
		philo->info->philos_full += 1;
	pthread_mutex_unlock(philo->info->check_lock);

}

void *routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while(1)
	{
		pthread_mutex_lock(philo->info->check_lock);
		if(philo->info->stop == 1)
		{
			pthread_mutex_unlock(philo->info->check_lock);
			break;
		}
		pthread_mutex_unlock(philo->info->check_lock);
		print_event(philo , philo->info->print_lock , "is thinking");
		eat_fun(philo);
		print_event(philo , philo->info->print_lock , "is sleeping");
		usleep(philo->info->tts * 1000);
	}
	return NULL;
}

int create_thread(t_philo	*philo)
{
	int i = 0;
	int num_philo = philo[i].info->num_phi;
	philo[i].info->start = get_time();
	pthread_t moni;
	pthread_create(&moni , NULL ,monitor , (void *)philo->info);
	while(i < num_philo)
	{
		if(pthread_create(&philo[i].thread , NULL ,routine , (void *)&philo[i]))
			return (-1);
		i++;
	}
	pthread_join(moni, NULL);
	i = 0;
	while(i < num_philo)
	{
		if(pthread_join(philo[i].thread, NULL))
			return (-1);
		i++;
	}
	return 0;
}
