/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:20:31 by yel-alja          #+#    #+#             */
/*   Updated: 2025/04/04 14:42:36 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_number(t_info *info , char **str)
{
	int i = 0;
	int j;
	while(str[i])
	{
		j = 0;
		while(str[i][j])
		{
			if(str[i][j] <= '0' && str[i][j] >= '9')
				return (-1);
			j++;
		}
		i++;
	}
	if(info->num_phi <= 0)
	{
		write(2 , "invalid of number of philos\n" , 28);
		return (-1);
	}
	return (0);
}

int init_info(t_info *info ,char **av)
{
	int i = 0;
	info->num_phi = ft_atoi(av[1] , &i);
	info->ttd = ft_atoi(av[2] , &i);
	info->tte = ft_atoi(av[3] , &i);
	info->tts = ft_atoi(av[4] , &i);
	if(av[5])
		info->noe = ft_atoi(av[5] , &i);
	if(i == -1 || check_number(info , av) == -1)
		return (-1);
	return (0);
}
