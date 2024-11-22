/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:33:49 by gabrfern          #+#    #+#             */
/*   Updated: 2024/11/21 18:32:09 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	died_from_starve(t_philo *philo)
{
	do_mutex_action(&philo->mtx_starve_time, LOCK);
	if (philo->starve_time <= get_current_milis())
	{
		do_mutex_action(&philo->mtx_starve_time, UNLOCK);
		return (1);
	}
	do_mutex_action(&philo->mtx_starve_time, UNLOCK);
	return (0);
}

static int	end_table(t_table **tb)
{
	do_mutex_action(&(*tb)->mtx_end_run, LOCK);
	if (!(*tb)->end_run)
	{
		(*tb)->end_run = 1;
		do_mutex_action(&(*tb)->mtx_end_run, UNLOCK);
		return (1);
	}
	do_mutex_action(&(*tb)->mtx_end_run, UNLOCK);
	return (0);
}

int	is_philo_full(t_philo *philo)
{
	do_mutex_action(&philo->mtx_lunch_ct, LOCK);
	if (philo->lunch_ct == philo->table->lunch_max)
	{
		do_mutex_action(&philo->mtx_lunch_ct, UNLOCK);
		return (1);
	}
	do_mutex_action(&philo->mtx_lunch_ct, UNLOCK);
	return (0);
}

int	all_lunched(t_philo *philo, int *lunch)
{
	if (is_philo_full(philo))
		(*lunch) = (*lunch) + 1;
	if ((*lunch) == philo->table->philo_count)
	{
		return (1);
	}
	return (0);
}

void	*judge_routine(void *ptr)
{
	t_table	*tb;
	int		i;
	int		limit;

	limit = 0;
	i = 0;
	tb = (t_table *)ptr;
	while (all_lunched(&tb->philo[i], &limit) == 0)
	{
		if (died_from_starve(&tb->philo[i]))
		{
			if (end_table(&tb) == 1)
			{
				communicate_action(&tb->philo[i], DIED);
				break ;
			}
		}
		i++;
		if (i == tb->philo_count)
			i = 0;
	}
	return (NULL);
}
