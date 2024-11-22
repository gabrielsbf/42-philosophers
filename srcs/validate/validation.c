/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:44:29 by gabrfern          #+#    #+#             */
/*   Updated: 2024/11/20 13:41:56 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_only_num(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	validate_input(char **args, int c_args)
{
	int	i;

	i = 1;
	if (c_args < 5 || c_args > 6)
		return (0);
	if (ft_atol(args[1]) >= 200)
		return (0);
	while (i < c_args)
	{
		if (!ft_only_num(args[i]))
			return (0);
		if (ft_atol(args[i]) > 2147483647
			|| ft_atol(args[i]) <= 0)
			return (0);
		i++;
	}
	return (1);
}
