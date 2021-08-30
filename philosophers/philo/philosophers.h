/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:29:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/30 22:35:42 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

int	store;

typedef struct s_philo
{
	int	die_flag;
}				t_philo;

typedef struct s_info
{
	int	philo_num;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	must_eat_num;
}				t_info;

#ifdef __cplusplus
extern "C"{
#endif /*__cplusplus */

	int increment(int i);
	int	ft_atoi(const char *nptr);

#ifdef __cplusplus
}
#endif /*__cplusplus */


#endif
