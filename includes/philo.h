/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 01:55:07 by gabrfern          #+#    #+#             */
/*   Updated: 2024/11/21 02:03:05 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "data_structs.h"

long	ft_atol(char *nptr);
t_table	*create_scenario(char **args, int c_args);
void	start_process(char **args, int c_args);
void	do_mutex_action(t_mutex *mtx, t_mtxcode code);
int		validate_input(char **args, int c_args);

//time functions
double	get_current_milis(void);
void	make_elapse(double pass_milis);
void	sleep_one_mili(void);

//free functions
void	free_structs(t_table **tb);

//states
int	is_thinking(t_philo *philo);
int	is_sleeping(t_philo *philo);
int	is_eating(t_philo *philo);

//routine
void	run_routine(t_table *tb);
int		assert_run(t_philo *philo);
void	communicate_action(t_philo *philo, t_philostate state);
void	set_starving_cron(t_philo *philo);

// DEBUG FUNCTION - NEED to erase.
void	print_tb(t_table *tb);
#endif
