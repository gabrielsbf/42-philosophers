/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 01:54:44 by gabrfern          #+#    #+#             */
/*   Updated: 2024/11/21 18:50:14 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_process(char **args, int c_args)
{
	t_table *tb;

	tb = create_scenario(args, c_args);
	print_tb(tb);
	run_routine(tb);
	free_structs(&tb);
}

int main(int argc, char *argv[])
{
	if (!validate_input(argv, argc))
	{
		printf("you inserted a bad input!\n");
		return (0);
	}
	start_process(argv, argc);
	return (0);
}
