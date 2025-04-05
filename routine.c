/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:23:01 by yel-alja          #+#    #+#             */
/*   Updated: 2025/04/05 16:55:44 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *arg)
{
pthread_mutex_t mutex;
	pthread_mutex_init(&mutex , NULL);
	pthread_mutex_lock(&mutex);
	int i = *(int *)arg;
	printf("%d\n" , i);
	pthread_mutex_unlock(&mutex);
	pthread_mutex_destroy(&mutex);
	return NULL;
}
int create_thread(t_info info)
{

	pthread_t thread[info.num_phi];
	int i = 0;
	while(i < info.num_phi)
	{
		if(pthread_create(&thread[i] , NULL , &routine , (void *)&i) != 0)
		{
			write(2 , "failed to create threads\n" , 25);
			return(-1);
		}
		usleep(500);
		i++;
	}
	i = 0;
	while(i < info.num_phi)
	{
		if(pthread_join(thread[i] , NULL))
		{
			write(2 , "faild to join threads\n", 22);
			return (-1);
		}
		i++;
	}
	return (0);
}
