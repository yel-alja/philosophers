/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:33:16 by yel-alja          #+#    #+#             */
/*   Updated: 2025/04/20 18:52:13 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	*monitor(void *args)
{
	t_info	*info;
	int		num;

	info = args;
	num = info->num_phi;
	while (1) // philo->info->death_flag
	{
		pthread_mutex_lock(info->check_lock);
		if ((info->philos_full == num) && (info->ac == 6))
		{
			info->stop = 1;
			pthread_mutex_unlock(info->check_lock);
			break ;
		}
		pthread_mutex_unlock(info->check_lock);
		usleep(1000);
	}
	return (NULL);
}
