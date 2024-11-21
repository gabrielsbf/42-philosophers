/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:50:45 by gabrfern          #+#    #+#             */
/*   Updated: 2024/11/21 18:15:30 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_thinking(t_philo *philo)
{
	if (assert_run(philo) == 0)
		return (0);
	communicate_action(philo, THINKING);
	return (1);

}

int	is_sleeping(t_philo *philo)
{
	if (assert_run(philo) == 0)
		return (0);
	communicate_action(philo, SLEEP);
	make_elapse(philo->tt_sleep);
	return (1);

}

static	void	return_fork(t_philo **philo)
{
	do_mutex_action(&(*philo)->l_fork->mtx_fork, LOCK);
	(*philo)->l_fork->in_use = 0;
	do_mutex_action(&(*philo)->l_fork->mtx_fork, UNLOCK);
	do_mutex_action(&(*philo)->r_fork->mtx_fork, LOCK);
	(*philo)->r_fork->in_use = 0;
	do_mutex_action(&(*philo)->r_fork->mtx_fork, UNLOCK);
}

static	int	get_side_fork(t_philo **philo, t_which_fork side)
{
	t_fork	*fork_choosen;

	if (side == LFORK)
		fork_choosen = (*philo)->l_fork;
	if (side == RFORK)
		fork_choosen = (*philo)->r_fork;
	do_mutex_action(&fork_choosen->mtx_fork, LOCK);
	if (fork_choosen->in_use == 0)
	{
		fork_choosen->in_use = 1;
		do_mutex_action(&fork_choosen->mtx_fork, UNLOCK);
		communicate_action((*philo), TOOK_FORK);
		return (1);
	}
	do_mutex_action(&fork_choosen->mtx_fork, UNLOCK);
	return (0);
}

int	is_eating(t_philo *philo)
{
	int	get_fork;

	get_fork = 0;
	if (assert_run(philo) == 0)
		return (0);
	while (assert_run(philo) == 1 && get_fork < 2)
	{
		if (get_fork == 0)
			get_fork += get_side_fork(&philo, LFORK);
		else
			get_fork += get_side_fork(&philo, RFORK);
	}
	if (get_fork == 2)
	{
		communicate_action(philo, EATING);
		do_mutex_action(&philo->mtx_lunch_ct, LOCK);
		philo->lunch_ct++;
		do_mutex_action(&philo->mtx_lunch_ct, UNLOCK);
		set_starving_cron(philo);
		make_elapse(philo->tt_eat);
		return_fork(&philo);
		return (1);
	}
	return (0);
}
