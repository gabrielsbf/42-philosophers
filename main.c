/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 01:54:44 by gabrfern          #+#    #+#             */
/*   Updated: 2024/05/15 21:25:04 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	philo_is_thinking(t_philo **philo)
{
	printf("%ld philosopher X %s\n", (*philo)->actual_elapsed, "is_thinking");
	make_elapse((*philo)->tt_think, &(*philo)->actual_elapsed);
}

void	philo_is_sleeping(t_philo **philo)
{
	printf("%ld philosopher X %s\n", (*philo)->actual_elapsed, "is_sleeping");
	make_elapse((*philo)->tt_sleep, &(*philo)->actual_elapsed);

}

void	philo_is_eating(t_philo **philo)
{
	printf("%ld philosopher X %s\n", (*philo)->actual_elapsed, "is_eating");
	make_elapse((*philo)->tt_eat, &(*philo)->actual_elapsed);

}

void	philo_states(t_philo **philo)
{
	printf("die: %ld; eat: %ld; sleep: %ld", (*philo)->tt_die,(*philo)->tt_eat, (*philo)->tt_sleep);
	while (1)
	{
		// philo_is_thinking((philo));
		philo_is_eating((philo));
		philo_is_sleeping((philo));
	}
}


int main(int argc, char *argv[])
{
	if (argc == 5 || argc == 6)
	{
		t_philo *philo;
		philo = malloc(sizeof(t_philo));
		philo->tt_eat = ft_atol(argv[3]);
		philo->tt_think = ft_atol(argv[4]);
		philo_states(&philo);
	}
	else
	{
		printf("the program receives the arguments:\n>>> number_of_philosopher");
		printf("\n>>> time_to_die\n>>> time_to_eat\n>>> time_to_sleep\n");
		printf(">>> optional[number_of_times_each_philosopher_must_eat] \n");
	}
}
