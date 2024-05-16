/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 01:55:07 by gabrfern          #+#    #+#             */
/*   Updated: 2024/05/15 21:06:13 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>

typedef struct philosophers
{
	long	tt_eat;
	long	tt_think;
	long	tt_sleep;
	long	tt_die;
	long	philo_numb;
	long	actual_elapsed;
}	t_philo;

long	ft_atol(char *nptr);
void	philo_is_thinking(t_philo **philo);
void	philo_is_sleeping(t_philo **philo);
void	philo_is_eating(t_philo **philo);
void	philo_states(t_philo **philo);
double	get_current_milis(void);
void	make_elapse(long time_break, long *elapsed_time);
void	sleep_one_mili(void);
#endif
