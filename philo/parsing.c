/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:20:31 by yel-alja          #+#    #+#             */
/*   Updated: 2025/05/06 09:01:18 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_number(t_info *info, char **str, int i, int j)
{
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '+')
			j++;
		while (str[i][j])
		{
			if (str[i][j] < '0' || str[i][j] > '9')
			{
				write(2, "invalid input\n", 14);
				return (-1);
			}
			j++;
		}
		i++;
	}
	if (info->num_phi <= 0 || info->tts <= 0 || info->ttd <= 0 || info->tte <= 0
		|| info->noe <= 0)
	{
		write(2, "invalid input\n", 14);
		return (-1);
	}
	return (0);
}

void	ft_clean(pthread_mutex_t *forks, pthread_mutex_t *meal, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_phi)
	{
		pthread_mutex_destroy(&forks[i]);
		pthread_mutex_destroy(&meal[i]);
		i++;
	}
	pthread_mutex_destroy(&info->print_lock);
	pthread_mutex_destroy(&info->check_lock);
	pthread_mutex_destroy(&info->death_lock);
}

void	init_philo(t_philo *philo, t_info *info, pthread_mutex_t *forks,
		pthread_mutex_t *meal_mutex)
{
	int	i;

	i = 0;
	while (i < info->num_phi)
	{
		philo[i].id = i + 1;
		philo[i].right_fork = &forks[i];
		philo[i].meal_mutex = &meal_mutex[i];
		philo[i].left_fork = &forks[(i + 1) % info->num_phi];
		philo[i].info = info;
		philo[i].times_eat = 0;
		philo[i].last_meal = 0;
		i++;
	}
}

int	create_philo(t_info *info)
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*meal_mutex;

	forks = malloc(sizeof(pthread_mutex_t) * info->num_phi);
	if (!forks)
		return (-1);
	meal_mutex = malloc(sizeof(pthread_mutex_t) * info->num_phi);
	if (!meal_mutex)
		return (free(forks), -1);
	philo = malloc(sizeof(t_philo) * info->num_phi);
	if (!philo)
		return (free(forks), -1);
	initialize_mutexes(forks, info, meal_mutex);
	init_philo(philo, info, forks, meal_mutex);
	create_thread(philo);
	ft_clean(forks, meal_mutex, info);
	return (free(philo), free(info), free(forks), free(meal_mutex), 0);
}

int	init_info(t_info *info, char **av, int ac)
{
	int	i;

	*info = (t_info){0};
	i = 0;
	info->ac = ac;
	info->num_phi = ft_atoi(av[1], &i);
	info->ttd = ft_atoi(av[2], &i);
	info->tte = ft_atoi(av[3], &i);
	info->tts = ft_atoi(av[4], &i);
	if (ac == 6)
		info->noe = ft_atoi(av[5], &i);
	else
		info->noe = INT_MAX;
	if (i == -1 || check_number(info, av, 1, 0) == -1 || create_philo(info)
		== -1)
		return (free(info), -1);
	return (0);
}
