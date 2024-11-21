/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 01:55:07 by gabrfern          #+#    #+#             */
/*   Updated: 2024/11/21 18:06:24 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCTS_H
# define DATA_STRUCTS_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>

typedef pthread_mutex_t	t_mutex;

typedef struct s_table	t_table;

typedef enum which_fork
{
	LFORK,
	RFORK
}	t_which_fork;

typedef enum mtx_codes
{
	INIT,
	LOCK,
	UNLOCK,
	DESTROY,
}	t_mtxcode;

typedef enum philo_state
{
	TOOK_FORK,
	EATING,
	SLEEP,
	THINKING,
	DIED,
} t_philostate;

typedef	struct s_fork
{
	t_mutex	mtx_fork;
	int		fork_id;
	int		in_use;
}	t_fork;

typedef struct s_philosophers
{
	int			id;
	long		tt_eat;
	long		tt_sleep;
	long		tt_die;
	long		lunch_ct;
	double		starve_time;
	t_table		*table;
	t_fork		*r_fork;
	t_fork		*l_fork;
	t_mutex		mtx_lunch_ct;
	t_mutex		mtx_starve_time;
	pthread_t	thread;

}	t_philo;

struct s_table
{
	int			philo_count;
	double		timer;
	long		tt_die;
	long		tt_eat;
	long		tt_sleep;
	int			end_run;
	int			lunch_ct;
	int			lunch_max;
	t_mutex		mtx_print;
	t_mutex		mtx_end_run;
	t_mutex		mtx_lunch_max;
	t_philo		*philo;
	t_fork		*fork;
};

#endif
