/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:14:10 by gabrfern          #+#    #+#             */
/*   Updated: 2024/11/21 18:49:55 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	remove_mtx(t_table **tb)
{
	int	i;

	i = 0;
	do_mutex_action(&(*tb)->mtx_end_run, DESTROY);
	do_mutex_action(&(*tb)->mtx_lunch_max, DESTROY);
	do_mutex_action(&(*tb)->mtx_print, DESTROY);
	while ((*tb)->philo_count > i)
	{
		do_mutex_action(&(*tb)->philo[i].mtx_lunch_ct, DESTROY);
		do_mutex_action(&(*tb)->philo[i].mtx_starve_time, DESTROY);
		i++;
	}
	i = 0;
	while ((*tb)->philo_count > i)
	{
		do_mutex_action(&(*tb)->fork[i].mtx_fork, DESTROY);
		i++;
	}
}

void	free_structs(t_table **tb)
{
	remove_mtx(tb);
	free((*tb)->fork);
	free((*tb)->philo);
	free(*tb);
}
