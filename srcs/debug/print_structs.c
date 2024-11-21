/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_structs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:43:27 by gabrfern          #+#    #+#             */
/*   Updated: 2024/11/21 02:32:45 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_tb(t_table *tb)
{
	int		i;

	printf("-------------------INITIATING PRINT STRUCT-------------------\n");
	i = 0;
	printf("Number of philos -> %d\n", tb->philo_count);
	printf("eat > %ld | die > %ld | sleep %ld\n", tb->tt_eat, tb->tt_die, tb->tt_sleep);
	printf("---------------------------------------\n");
	while (i < tb->philo_count)
	{
		printf("PHILO -> id %d | left_fork id %d, right_fork id %d\n", tb->philo[i].id, tb->philo[i].l_fork->fork_id, tb->philo[i].r_fork->fork_id);
		i++;
		printf("---------------------------------------\n");
	}
	printf("\n-------------------ENDING PRINT STRUCT-------------------\n");
}
