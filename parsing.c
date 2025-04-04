/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:20:31 by yel-alja          #+#    #+#             */
/*   Updated: 2025/04/04 10:20:43 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_info(t_info *info ,char **av)
{
	int i = 0;
	info->num_phi = ft_atoi(av[1] , &i);
	info->ttd = ft_atoi(av[2] , &i);
	info->tte = ft_atoi(av[3] , &i);
	info->tts = ft_atoi(av[4] , &i);
	info->noe = ft_atoi(av[5] , &i);
	if(i == -1)
		return (-1);
	return (0);
}
