/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:08:54 by gabrfern          #+#    #+#             */
/*   Updated: 2024/11/21 01:22:31 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(void)
{
	double time_now = get_current_milis();
	printf("elapsed time->%f\n", time_now);
	make_elapse(15);
	printf("time passed: %f\n", time_now - get_current_milis());
}
