/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:12:22 by gabrfern          #+#    #+#             */
/*   Updated: 2024/11/21 02:53:52 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_starving_cron(t_philo *philo)
{
	do_mutex_action(&philo->mtx_starve_time, LOCK);
	philo->starve_time = get_current_milis() + philo->tt_die;
	do_mutex_action(&philo->mtx_starve_time, UNLOCK);
}

void	communicate_action(t_philo *philo, t_philostate state)
{
	double elapsed;
	do_mutex_action(&philo->table->mtx_print, LOCK);
	elapsed = get_current_milis() - philo->table->timer;
	printf("%ld - %d ", (long)elapsed, philo->id);
	if (state == TOOK_FORK)
		printf("has taken a fork\n");
	if (state == EATING)
		printf("is eating\n");
	if (state == SLEEP)
		printf("is sleeping\n");
	if (state == THINKING)
		printf("is thinking\n");
	if (state == DIED)
		printf("died\n");
	do_mutex_action(&philo->table->mtx_print, UNLOCK);

}

int	assert_run(t_philo *philo)
{
	do_mutex_action(&philo->table->mtx_end_run, LOCK);
	//check if philo is full to
	if (philo->table->end_run == 1)
	{
		do_mutex_action(&philo->table->mtx_end_run, UNLOCK);
		return (0);
	}
	do_mutex_action(&philo->table->mtx_end_run, UNLOCK);
	return (1);
}

static void	*philo_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	set_starving_cron(philo);
	if (philo->id % 2 == 0)
		make_elapse(0.060);
	// printf("passed elapse\n");
	while (assert_run(philo) == 1)
	{
		if (!is_thinking(philo))
		{
			printf("break on thinking\n");
			break ;
		}
		if (!is_eating(philo))
		{
			printf("break on eating\n");
			break ;
		}
		if (!is_sleeping(philo))
		{
			printf("break on sleeping\n");
			break ;
		}
	}
	printf("SAIU?\n");
	return (NULL);
}

void	run_routine(t_table *tb)
{
	int	i;

	i = -1;
	tb->timer = get_current_milis();
	while (++i < tb->philo_count)
		pthread_create(&tb->philo[i].thread, NULL,
			philo_routine, (void *)&tb->philo[i]);
	i = -1;
	while (++i < tb->philo_count)
		pthread_join(tb->philo[i].thread, NULL);
}
