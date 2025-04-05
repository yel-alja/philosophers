/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:19:28 by yel-alja          #+#    #+#             */
/*   Updated: 2025/04/05 16:50:24 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <pthread.h>
#include <stdlib.h>



typedef struct s_info
{
	int num_phi;
	int ttd;
	int tte;
	int tts;
	int noe;
} t_info;

int	ft_atoi(char *str , int *c);
int init_info(t_info *info ,char **av);
int create_thread(t_info info);
