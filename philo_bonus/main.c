/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:51:04 by yel-alja          #+#    #+#             */
/*   Updated: 2025/05/06 09:51:04 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_info	*info;

	if (ac != 6 && ac != 5)
	{
		printf("usage: ./philo_bonus <number_of_philosophers> <time_to_die> ");
		printf("<time_to_eat> <time_to_sleep>  ");
		printf("[number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	info = malloc(sizeof(t_info));
	if (!info)
		return (1);
	if (init_info(info, av, ac) == -1)
		return (1);
}
