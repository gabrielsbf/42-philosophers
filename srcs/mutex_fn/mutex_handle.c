/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_mutex_action.c                                     :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:49:54 by gabrfern          #+#    #+#             */
/*   Updated: 2024/11/20 19:43:01 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	do_mutex_action(t_mutex *mtx, t_mtxcode code)
{
	if (code == INIT)
		pthread_mutex_init(mtx, NULL);
	if (code == LOCK)
		pthread_mutex_lock(mtx);
	if (code == UNLOCK)
		pthread_mutex_unlock(mtx);
	if (code == DESTROY)
		pthread_mutex_destroy(mtx);
}
