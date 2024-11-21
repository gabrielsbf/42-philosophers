/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:58:41 by gabrfern          #+#    #+#             */
/*   Updated: 2024/11/21 15:40:29 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_forks(t_table *tb, t_fork **tb_fork)
{
	int	i;

	i = 0;
	*tb_fork = malloc(sizeof(t_fork) * tb->philo_count);
	while (i < tb->philo_count)
	{
		(*tb_fork)[i].fork_id = i + 1;
		(*tb_fork)[i].in_use = 0;
		do_mutex_action(&(*tb_fork)[i].mtx_fork, INIT);
		i++;
	}
}

static void call_philos(t_table *tb, t_philo **philo)
{
	int	i;

	i = 0;
	(*philo) = malloc(sizeof(t_philo) * tb->philo_count);
	while (i < tb->philo_count)
	{
		(*philo)[i].table = tb;
		(*philo)[i].id = i + 1;
		(*philo)[i].starve_time = 0;
		(*philo)[i].lunch_ct = 0;
		(*philo)[i].tt_die = tb->tt_die;
		(*philo)[i].tt_eat = tb->tt_eat;
		(*philo)[i].tt_sleep = tb->tt_sleep;
		(*philo)[i].l_fork = &tb->fork[i];
		(*philo)[i].r_fork = &tb->fork[(i + 1) % tb->philo_count];
		do_mutex_action(&((*philo)[i]).mtx_starve_time, INIT);
		do_mutex_action(&((*philo)[i]).mtx_lunch_ct, INIT);
		i++;
	}
}
static t_table	*fill_table(t_table *tb, char **args, int c_args)
{

	tb->philo_count = ft_atol(args[1]);
	tb->tt_die = ft_atol(args[2]);
	tb->tt_eat = ft_atol(args[3]);
	tb->tt_sleep = ft_atol(args[4]);
	tb->lunch_ct = 0;
	if (c_args == 6)
		tb->lunch_max = ft_atol(args[5]);
	else
		tb->lunch_max = -1;
	tb->end_run = 0;
	do_mutex_action(&tb->mtx_end_run, INIT);
	do_mutex_action(&tb->mtx_print, INIT);
	set_forks(tb, &tb->fork);
	call_philos(tb, &tb->philo);
	return (tb);
}

t_table	*create_scenario(char **args, int c_args)
{
	t_table * tb;

	tb = malloc(sizeof(t_table));
	tb = fill_table(tb, args, c_args);
	return (tb);
}

