/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:11:50 by gabrfern          #+#    #+#             */
/*   Updated: 2024/05/15 21:28:16 by gabrfern         ###   ########.fr       */
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

void	make_elapse(long time_break, long *elapsed_time)
{
	double	time_to_compare;
	double	actual_elapsed;

	actual_elapsed = 0;
	time_to_compare = get_current_milis();
	while(get_current_milis() - time_to_compare < time_break)
	{
		usleep(1000);
		actual_elapsed = get_current_milis() - time_to_compare;
	}
	*elapsed_time = *elapsed_time + (long)actual_elapsed;

}

void	sleep_one_mili(void)
{
	int	i;

	i = 1;
	while(i <= 10)
	{
		usleep(100);
		i++;
	}
}
