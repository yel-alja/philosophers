/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:20:31 by yel-alja          #+#    #+#             */
/*   Updated: 2025/04/21 11:03:53 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_number(t_info *info, char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
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

void	initialize_mutexes(pthread_mutex_t *forks, pthread_mutex_t *print_lock,
		int i, pthread_mutex_t *check_lock)
{
	int	j;

	j = 0;
	while (j < i)
	{
		pthread_mutex_init(&forks[j], NULL);
		j++;
	}
	pthread_mutex_init(print_lock, NULL);
	pthread_mutex_init(check_lock, NULL);
}

int	create_philo(t_info *info)
{
	int				i;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*check_lock;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * info->num_phi);
	if (!forks)
		return (-1);
	philo = malloc(sizeof(t_philo) * info->num_phi);
	if (!philo)
		return (free(forks), -1);
	print_lock = malloc(sizeof(pthread_mutex_t));
	if (!print_lock)
		return (free(forks), free(philo), -1);
	check_lock = malloc(sizeof(pthread_mutex_t));
	if (!check_lock)
		return (free(forks), free(print_lock), free(philo), -1);
	initialize_mutexes(forks, print_lock, info->num_phi, check_lock);
	info->print_lock = print_lock;
	info->check_lock = check_lock;
	while (i < info->num_phi)
	{
		philo[i].id = i + 1;
		philo[i].right_fork = &forks[i];
		philo[i].left_fork = &forks[(i + 1) % info->num_phi];
		philo[i].info = info;
		philo[i].times_eat = 0;
		i++;
	}
	if (create_thread(philo) == -1)
		return (free(forks), free(philo), free(print_lock), free(print_lock),
			-1);
	return (free(check_lock), free(philo), free(info), free(forks),
		free(print_lock), 0);
}

int	init_info(t_info *info, char **av, int ac)
{
	int	i;

	i = 0;
	info->ac = ac;
	info->philos_full = 0;
	info->stop = 0;
	info->num_phi = ft_atoi(av[1], &i);
	info->ttd = ft_atoi(av[2], &i);
	info->tte = ft_atoi(av[3], &i);
	info->tts = ft_atoi(av[4], &i);
	if (ac == 6)
		info->noe = ft_atoi(av[5], &i);
	else
		info->noe = INT_MAX;
	if (i == -1 || check_number(info, av) == -1 || create_philo(info) == -1)
		return (free(info), -1);
	return (0);
}
