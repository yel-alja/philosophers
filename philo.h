/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:19:28 by yel-alja          #+#    #+#             */
/*   Updated: 2025/04/04 10:20:51 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <limits.h>


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
