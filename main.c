/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:51:04 by yel-alja          #+#    #+#             */
/*   Updated: 2025/04/04 10:20:23 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int main(int ac , char **av)
{
	t_info info;

	if(ac != 6)
	{
		printf("the arguments must be like this ./philo <number_of_philosophers> <time_to_die> <time_to_eat> ");
		printf("<time_to_sleep>  [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	if(init_info(&info , av) == -1)
		return (1);
}
