/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 01:54:44 by gabrfern          #+#    #+#             */
/*   Updated: 2024/04/30 03:07:23 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

double	get_current_milis(void)
{
	struct timeval	*time_passed;
	double			seconds_to_mili;
	double			micro_to_mili;
	
	time_passed = malloc(sizeof(struct timeval));
	gettimeofday(time_passed, NULL);
	seconds_to_mili = time_passed->tv_sec * 1000;
	micro_to_mili = time_passed->tv_usec / 1000;
	free(time_passed);
	return (seconds_to_mili + micro_to_mili);
}

void make_elapse(int time_break, char *prompt)
{
	double	time_to_compare;
	double	actual_elapsed;

	actual_elapsed = 0;
	time_to_compare = get_current_milis();
	while(get_current_milis() - time_to_compare < time_break)
	{
		actual_elapsed = get_current_milis() - time_to_compare;
		printf("%lf philosopher X %s\n", actual_elapsed, prompt);
		usleep(800);
	}
	
}

void	philo_is_thinking(int time_to_think)
{
	make_elapse(time_to_think, "is_thinking");
}

void	philo_is_sleeping(int time_to_sleep)
{
	make_elapse(time_to_sleep, "is_sleeping");
	
}

void	philo_is_eating(int time_to_eat)
{
	make_elapse(time_to_eat, "is_eating");
}

void	philo_states(char *argv[])
{
    int philo_num;
	
    philo_num = ft_atol(argv[1]);
	while (1)
	{
		philo_is_eating(ft_atol(argv[3]));
		philo_is_sleeping(ft_atol(argv[4]));
	}
}






int main(int argc, char *argv[])
{
	if (argc == 5 || argc == 6)
	{
		philo_states(argv);
	}
	else
	{
		printf("the program receives the arguments:\n>>>number_of_philosopher");
		printf("\n>>>time_to_die\n>>>time_to_eat\n>>>time_to_sleep\n");
		printf("and the additional [number_of_times_each_philosopher_must_eat]\n");
	}
}
	